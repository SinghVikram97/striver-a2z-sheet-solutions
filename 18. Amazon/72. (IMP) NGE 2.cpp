// https://leetcode.com/problems/next-greater-element-ii/description/

/*
Circular array double it programatically

arr=[2,10,12,1,11]

arr = 2, 10, 12, 1, 11, 2, 10, 12, 1, 11
      0   1   2  3   4  5   6   7  8   9

real index will be i % N ie. i%5

and starting from any element for example i=2 how many elements to the right would be our unique array n elements
since array length n
so from 12 we traverse till index = 6 for our original array 

TC: O(N^2)
*/
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();

        vector<int> nge(n,-1);

        for(int i=0;i<n;i++){
            for(int j=i+1;j<=i+n-1;j++){
                int realIndex = j%n;

                if(nums[realIndex]>nums[i]){
                    nge[i]=nums[realIndex];
                    break;
                }
            }
        }


        return nge;
    }
};


/*
We use monotonic stack concept
arr=[2,10,12,1,11]

arr = 2, 10, 12, 1, 11, 2, 10, 12, 1, 11
      0   1   2  3   4  5   6   7  8   9

We start from 2*n-1 
where n=5
*/
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();

        vector<int> nge(n,-1);

        stack<int> ms;
        for(int i=(2*n)-1;i>=0;i--){
            int realIndex = i%n;

            while(!ms.empty() && nums[realIndex]>=ms.top()){
                ms.pop();
            }

            if(i<n){
                // have to calculate nge
                if(ms.empty()){
                    nge[i]=-1;
                }else{
                    nge[i]=ms.top();
                }
            }

            ms.push(nums[realIndex]);
        }


        return nge;
    }
};