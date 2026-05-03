// https://leetcode.com/problems/copy-list-with-random-pointer/description/
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node *newHead=NULL;
        Node *prev=NULL;
        unordered_map<Node *, Node *> mp; // original -> copy

        Node *temp=head;
        while(temp!=NULL){
            Node *newNode = new Node(temp->val);

            if(prev==NULL){
                newHead=newNode;
                prev=newNode;
            }else{
                prev->next=newNode;
                prev=newNode;
            }

            mp[temp]=newNode;
            temp=temp->next;
        }

        Node *temp1=head;
        Node *temp2=newHead;
        while(temp1!=NULL){
            if(temp1->random!=NULL){
                temp2->random=mp[temp1->random];
            }

            temp1=temp1->next;
            temp2=temp2->next;
        }

        return newHead;
    }
};

// O(1)
/*
Store new nodes in b/w of original list ie.

1->2->3->4->5 : Original list

1->1'->2->2'->3->3' : Original list

random remains same in original list

now we can go from 1 to 4 (ie. it's random and its next would be 4')


*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node *cur=head;

        // Insert in b/w
        while(cur!=NULL){
            Node *newNode = new Node(cur->val);
            Node *temp = cur->next;
            cur->next = newNode;
            newNode->next=temp;
            cur=temp;
        }

        // Add random nodes for copy nodes
        cur = head;
        while(cur!=NULL){
            Node *randomNode = cur->random;
            Node *copyNode = cur->next;

            if(randomNode!=NULL){
                copyNode->random = randomNode->next;
            }
            cur=cur->next->next;
        }


        // Remove interleaving
        Node *newHead=NULL;
        Node *prev=NULL;
        cur=head;
        while(cur!=NULL){
            Node *copyNode = cur->next;
            // fix original list
            cur->next=cur->next->next;

            if(prev==NULL){
                newHead=copyNode;
                prev=copyNode;
            }else{
                prev->next=copyNode;
                prev=copyNode;
            }

            // since we fixed next so not cur->next->next here
            cur=cur->next;
        }

        return newHead;
    }
};
