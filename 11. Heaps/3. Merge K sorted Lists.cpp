// https://leetcode.com/problems/merge-k-sorted-lists/description/
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();

        if(n==0){
            return NULL;
        }

        int last=n-1;

        while(last!=0){
            int i=0;
            int j=last;

            while(i<j){
                lists[i]=mergeList(lists[i],lists[j]);
                i++;
                j--;
            }
            last=j;
        }

        return lists[0];
    }
};