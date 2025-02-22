// https://leetcode.com/problems/reverse-nodes-in-k-group
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        // If num of nodes < k then leave them as it is
        int count=0;
        ListNode *temp=head;

        while(temp!=NULL && count<k){
            temp=temp->next;
            count++;
        }

        // either temp is null or count is k or both
        if(temp==NULL && count!=k){
            return head; // less than k nodes
        }

        // reverse k nodes
        ListNode *prev=NULL;
        ListNode *cur=head;
        ListNode *next=NULL;
        ListNode *lastNodeInReverse=head;
        count=0;

        while(count!=k){
            count++;
            next=cur->next;
            cur->next=prev;
            prev=cur;
            cur=next;
        }

        // connect last node of reversed list to next group
        ListNode *nextGroup=reverseKGroup(next,k);

        lastNodeInReverse->next=nextGroup;

        return prev;
    }
};