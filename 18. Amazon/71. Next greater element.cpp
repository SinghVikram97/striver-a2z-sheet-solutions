// https://leetcode.com/problems/next-greater-element-i/description/
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n=nums2.size();

        stack<int> ms;
        // element, nextGreaterElement
        unordered_map<int,int> mp;

        for(int i=n-1;i>=0;i--){
            // no use of elements which are less since nums[i] would be the ans for remaining elements to the left
            while(!ms.empty() && nums2[i]>ms.top()){
                ms.pop();
            }

            if(ms.empty()){
                mp[nums2[i]]=-1;
            }else{
                mp[nums2[i]]=ms.top();
            }

            ms.push(nums2[i]);
        }

        vector<int> ans;

        for(int i=0;i<nums1.size();i++){
            ans.push_back(mp[nums1[i]]);
        }

        return ans;
        
    }
};