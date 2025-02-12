/*
If we are given elements greater than n/k

n/k + n/k + n/k ..... k times = n
So atmost k-1 elements can be greater than n/k

 */
class Solution {
public:
    vector<int> generalized(vector<int> &nums, int k){
        vector<int> counts(k-1, 0);
        vector<int> elements(k-1, INT_MIN);
        int n=nums.size();

        for(int i=0;i<n;i++){
            bool found=false;
            for(int j=0;j<counts.size();j++){
                if(nums[i]==elements[j]){
                    counts[j]++;
                    found=true;
                    break;
                }
            }

            if(!found){
                bool newCandidate = false;
                for(int j=0;j<counts.size();j++){
                    if(counts[j]==0){
                        elements[j]=nums[i];
                        counts[j]=1;
                        newCandidate=true;
                        break;
                    }
                }

                if(!newCandidate){
                    for(int j=0;j<counts.size();j++){
                        counts[j]--;
                    }       
                }         
            }
        }

        int majorityFreq=n/k;
        vector<int> ans;
        for(int j=0;j<counts.size();j++){
            int actualCount=0;
            for(int i=0;i<n;i++){
                if(nums[i]==elements[j]){
                    actualCount++;
                }
            }

            if(actualCount>majorityFreq){
                ans.push_back(elements[j]);
            }
        }

        return ans;
    }
    vector<int> majorityElement(vector<int>& nums) {
        return generalized(nums, 3);
    }
};