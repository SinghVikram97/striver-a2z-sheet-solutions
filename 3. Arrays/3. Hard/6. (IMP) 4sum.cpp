// https://leetcode.com/problems/4sum/description/

// Brute force - O(n^4)
// Fix 2 and then 2 sum - O(n^3)
// Generate all pairs and then apply 2 sum on pairs array - O(n^2)

class Pair{
public:
    int num1;
    int num2;
    int index1;
    int index2;
    int sum;
    
    Pair(int num1, int num2, int index1, int index2, int sum){
        this->num1=num1;
        this->num2=num2;
        this->index1=index1;
        this->index2=index2;
        this->sum=sum;
    }
};
bool noCommon(Pair a,Pair b){
    
    if(a.index1==b.index1 || a.index1==b.index2 || a.index2==b.index1 || a.index2==b.index2){
        return false;
    }
    return true;
}
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n=nums.size();
        
        vector<Pair> pairArray;

        // generate all pairs
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                pairArray.push_back(Pair(nums[i], nums[j], i, j, nums[i]+nums[j]));
            }
        }

        // Now apply 2 sum on pairs
        n=pairArray.size();

        // sort
        sort(pairArray.begin(), pairArray.end(), [](const auto &a, const auto &b){
            return a.sum<b.sum;
        });

        vector<vector<int> > ans;
        int start=0;
        int end=n-1;

        while(start<end){
            Pair pair1=pairArray[start];
            Pair pair2=pairArray[end];

            int currentSum=pair1.sum+pair2.sum;

            if(currentSum==target){
                if(noCommon(pair1, pair2)){
                    ans.push_back({pair1.num1, pair1.num2, pair2.num1, pair2.num2});
                }
                start++;
                end--;
            }else if(currentSum<target){
                start++;
            }else{
                end--;
            }
        }
        return ans;
    }
};


// Above solution doesn't work with duplicates
/*
We want to avoid duplicates so we sort to skip duplicate numbers and then use same technique as 3sum
take 2 loops and fix 2 numbers and then remaining 2 via 2sum -> o(n^3)
*/
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n=nums.size();

        sort(nums.begin(), nums.end());

        vector<vector<int> > ans;

        // n-4 n-3 n-2 n-1
        for(int i=0;i<=n-4;i++){
            for(int j=i+1;j<=n-3;j++){
                // fix nums[i] and nums[j]
                long long int currentSum=nums[i]+nums[j];
                long long int targetSum=target-currentSum;

                int start=j+1;
                int end=n-1;

                while(start<end){
                    long long int sum=nums[start]+nums[end];

                    if(sum==targetSum){
                        ans.push_back({nums[i], nums[j], nums[start], nums[end]});

                        int curStart=nums[start];
                        while(start<end && nums[start]==curStart){
                            start++;
                        }

                        int curEnd=nums[end];
                        while(start<end && nums[end]==curEnd){
                            end--;
                        }
                        // above both loops guarenteed to proceed by one even if no duplicates

                        if(start>=end){
                            break;
                        }
                        
                    }else if(sum<targetSum){
                        start++;
                    }else{
                        end--;
                    }
                }

                // skip duplicates for j
                while(j<n-3 && nums[j+1]==nums[j]){
                    j++;
                }
            }
            // skip duplicates for i
            while(i<n-4 && nums[i+1]==nums[i]){
                i++;
            }
        }

        return ans;
    }
};