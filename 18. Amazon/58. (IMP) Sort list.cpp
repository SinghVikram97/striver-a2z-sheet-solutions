// https://leetcode.com/problems/sort-list/description/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeList(ListNode *first, ListNode *second){
        ListNode* temp1=first;
        ListNode* temp2=second;
        ListNode* prev=NULL;
        ListNode* newHead=NULL;

        while(temp1!=NULL && temp2!=NULL){
            if(temp1->val<=temp2->val){
                if(prev==NULL){
                    prev=temp1;
                    newHead=temp1;
                }else{
                    prev->next=temp1;
                    prev=temp1;
                }
                temp1=temp1->next;
            }else{
                if(prev==NULL){
                    prev=temp2;
                    newHead=temp2;
                }else{
                    prev->next=temp2;
                    prev=temp2;
                }
                temp2=temp2->next;
            }
        }

        while(temp1!=NULL){
            if(prev==NULL){
                    prev=temp1;
                    newHead=temp1;
            }else{
                    prev->next=temp1;
                    prev=temp1;
            }
            temp1=temp1->next;
        }
        while(temp2!=NULL){
            if(prev==NULL){
                    prev=temp2;
                    newHead=temp2;
            }else{
                    prev->next=temp2;
                    prev=temp2;
            }
            temp2=temp2->next;
        }
        return newHead;
    }
    ListNode* sortList(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }

        // Split into two halves
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = NULL;

        while (fast != NULL && fast->next != NULL) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        // Break the list into two halves
        prev->next = NULL;

        // Recursively sort the two halves
        ListNode* left = sortList(head);
        ListNode* right = sortList(slow);

        // Merge the sorted halves
        return mergeList(left, right);
    }
};