// https://leetcode.com/problems/majority-element/
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count=1;
        int majorityEle=nums[0];

        int n=nums.size();

        for(int i=1;i<n;i++){
            if(nums[i]==majorityEle){
                count++;
            }
            else{
                count--;
            }

            if(count==0){
                majorityEle=nums[i];
                count=1;
            }
        }
        cout<<count<<endl;
        if(count>0){
            // exists
            return majorityEle;
        }

        return -1;
    }
};

// https://leetcode.com/problems/majority-element-ii/description/

/*
n/3

n/3+n/3+n/3 = n

So atmost 2 elements can be more than n/3

Takes care of duplicates like [3,3,2] by not assigning the same number to num1 and num2
*/
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();

        int num1=INT_MIN;
        int num2=INT_MIN;

        int count1=0;
        int count2=0;

        for(int i=0;i<n;i++){
            if(nums[i]==num1){
                count1++;
            }else if(nums[i]==num2){
                count2++;
            }else if(count1==0){ // using else if we don't assign same number to both num1 and num2
                // even if both became 0 in a loop
                num1=nums[i];
                count1=1;
            }else if(count2==0){
                num2=nums[i];
                count2=1;
            }else{
                count1--;
                count2--;
            }
        }

        vector<int> ans;
        int countMajority=n/3;
        count1=0;
        count2=0;

        for(int i=0;i<n;i++){
            if(nums[i]==num1){
                count1++;
            }
            if(nums[i]==num2){
                count2++;
            }
        }

        if(count1>countMajority){
            ans.push_back(num1);
        }

        if(count2>countMajority){
            ans.push_back(num2);
        }

        return ans;
    }
};

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