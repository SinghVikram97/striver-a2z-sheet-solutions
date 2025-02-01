// https://leetcode.com/problems/next-greater-element-i/description/

// we want to store elements in stack in ascending order ie. 3,4,10 with 3 on top
/*
Now 3 cases 

nums[i]<stack top -> ans would be stack top
nums[i]>stack top -> ans would be first element greater in stack
nums[i]=stack top -> same as above

Now we push nums[i] to stack and nums[i] would be < than stack top


*/

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