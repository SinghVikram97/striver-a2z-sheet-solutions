// https://leetcode.com/problems/merge-k-sorted-lists/

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
// O(n*logk)
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0){
            return NULL;
        }
        priority_queue<pair<int, ListNode*> , vector<pair<int, ListNode*>>, greater<pair<int, ListNode*>> > pq;

        // insert 1st element of every list into pq
        for(int i=0;i<lists.size();i++){
            if(lists[i]){
               pq.push(make_pair(lists[i]->val,lists[i]));
            }
        }

        ListNode *head=NULL;
        ListNode *prev=NULL;

        while(!pq.empty()){
            // take smallest out
            pair<int, ListNode*> topEle=pq.top();
            pq.pop();

            cout<<topEle.first<<" ";

            if(prev==NULL){
                head=topEle.second;
            }else{
                prev->next=topEle.second;
            }

            // push next element
            if(topEle.second->next){
                pq.push(make_pair(topEle.second->next->val,topEle.second->next));
            }

            prev=topEle.second;

        }
        return head;
    }
};