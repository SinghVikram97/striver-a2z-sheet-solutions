// https://leetcode.com/problems/longest-consecutive-sequence/description/
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        unordered_set<int> ms;
        for(int i=0;i<n;i++){
            ms.insert(nums[i]);
        }

        int maxi=0;
        while(!ms.empty()){
            auto it=ms.begin();
            int num=(*it);
            cout<<num<<endl;

            int temp=num+1;
            int numGreater=0;
            while(ms.find(temp)!=ms.end()){
                ms.erase(temp);
                temp++;
                numGreater++;
            }

            temp=num-1;
            int numSmaller=0;
            while(ms.find(temp)!=ms.end()){
                ms.erase(temp);
                temp--;
                numSmaller++;
            }

            ms.erase(num);
            maxi=max(maxi, 1+numGreater+numSmaller);
        }

        return maxi;
    }
};