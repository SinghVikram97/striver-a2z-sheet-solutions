// https://leetcode.com/problems/intersection-of-two-arrays/
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int i=0,j=0;
        int m=nums1.size();
        int n=nums2.size();
        vector<int> ans;

        while(i<m && j<n){
            if(nums1[i]==nums2[j]){
                if(ans.empty() || (!ans.empty() && ans.back()!=nums1[i])){
                    ans.push_back(nums1[i]);
                }
            }
            else if(nums1[i]<nums2[j]){
                i++;
            }
            else{
                j++;
            }
        }
        return ans;
    }
};