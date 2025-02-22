// https://leetcode.com/problems/add-two-numbers/description/
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *newHead=NULL;
        ListNode *prev=NULL;

        int num=0;
        int carry=0;
        while(l1!=NULL || l2!=NULL){
            int num1= (l1==NULL) ? 0 : l1->val;
            int num2= (l2==NULL) ? 0 : l2->val;
            
    
            num=num1+num2+carry;
            int finalNum=num%10;
            carry=num/10;

            if(prev==NULL){
                ListNode *newNode=new ListNode(finalNum);
                newHead=newNode;
                prev=newNode;
            }else{
                ListNode *newNode=new ListNode(finalNum);
                prev->next=newNode;
                prev=newNode;
            }

            if(l1!=NULL){
                l1=l1->next;
            }

            if(l2!=NULL){
                l2=l2->next;
            }
        }

        // if last numbers >= 10
        if(carry!=0){
            if(prev==NULL){
                ListNode *newNode=new ListNode(carry);
                newHead=newNode;
                prev=newNode;
            }else{
                ListNode *newNode=new ListNode(carry);
                prev->next=newNode;
                prev=newNode;
            }
        }

        return newHead;
    }
};