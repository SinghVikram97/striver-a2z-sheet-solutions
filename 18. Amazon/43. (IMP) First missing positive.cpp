// https://leetcode.com/problems/first-missing-positive/description/
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        // Use numbers as indexes and mark numbers
        // consider index 0 as marker for 1 since we want positive integers
        int n=nums.size();

        // size n = 5
        // indexes:
        // 1, 2, 3, 4, 5 

        // if all 5 present then all marked then ans=n+1
        // otherwise ans will be <=n which is missing number
        // so if a number > n or a number <=0 we can ignore them
        // so we mark then as 1 

        bool isOneMissing=true;
        for(int i=0;i<n;i++){
            if(nums[i]==1){
                isOneMissing=false;
            }else if(nums[i]<=0 || nums[i]>n){
                nums[i]=1;
            }
        }

        if(isOneMissing){
            return 1;
        }

        int increaseBy=n+1; // maximum number in our array now is n

        for(int i=0;i<n;i++){
            int index = (nums[i]%increaseBy);
            nums[index-1]+=increaseBy; // treat index 0 as marker for 1
        }

        // find missing
        int missing = n+1;

        for(int i=0;i<n;i++){
            if(nums[i]>=increaseBy){
                // marked
            }else{
                return i+1;
            }
        }

        return missing;
    }
};


// Revision
/*
Let's say array length is n

2 cases
1. missing number is n+1 ie. array contains 1,2,3..n
2. missing number <= n 

We can track each number that is <=n in that index (index-1) ie. use 0 as tracker for 1

How to track?
Increase by n+1 

so that when u get it back n%(n+1)= n (ie. 1+maxNumber)

But: numbers can <=0 or greater than n too in array - ignore them - make them 1
*/
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n=nums.size();

        bool oneMissing = true;
        for(int i=0;i<n;i++){
            if(nums[i]==1){
                oneMissing = false;
            }
            if(nums[i]<=0 || nums[i]>n){
                nums[i]=1;
            }
        }

        if(oneMissing){
            return 1;
        }

        int maxNumber = 1+n;

        for(int i=0;i<n;i++){
            int originalNumber = nums[i]%(maxNumber);
            // mark at that index - 1
            if(originalNumber!=0){
                nums[originalNumber-1]+=maxNumber;
            }
        }

        // Now check if all present
        for(int i=0;i<n;i++){
            if(nums[i]<maxNumber){
                // did not get marked
                return i+1; 
            }
        }

        // all present so answer is n+1
        return n+1;
    }
};
