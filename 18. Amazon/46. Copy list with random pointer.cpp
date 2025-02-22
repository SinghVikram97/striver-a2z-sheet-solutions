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