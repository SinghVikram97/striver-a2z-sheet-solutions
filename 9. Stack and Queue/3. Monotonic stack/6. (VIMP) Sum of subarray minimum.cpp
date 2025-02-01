// https://leetcode.com/problems/sum-of-subarray-minimums/description/

// Brute Force - TLE
#define m 1000000007
class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        long long int sum=0;
        for(int i=0;i<n;i++){
            int mini=INT_MAX;
            for(int j=i;j<n;j++){
                mini=min(mini, arr[j]);
                sum=((sum%m)+(mini%m))%m;
            }
        }
        return sum;
    }
};

/*
1 4 6 7 3 7 8 1

For element 3 , how many arrays would it minimum

3
3 7
3 7 8 
But not 3 7 8 1

similarly to the left
7 3
6 7 3
4 6 7 3

but not 1 4 6 7 3

Also it can be something like combination of left and right 7 3 7

ie. 4 6 7 3 7 8 all subarrays formed from this will have 3 as minimum

so 4 on the left and 3 on the right
what would be the total number of arrays you can generate = 4*3 = 12
So in 12 subarrays 3 would be ans so it would contribute 3*12 = 36 to the answer

Here is the easy explanation of how we are getting 12 subarrays. 
Consider the array where we want to focus, [4,6,7,3,7,8]. 
Here we want the sub array to include 3 which has to be contiguous. 
So we just need to find the possible choices for starting and ending of indices which makes the subarray. 
For 3 to be in the subarray, the number of choices we can have for starting index of subarray is 4 as indices 0,1,2,3 are possible 
where 3 is at the index 3, 
and for the ending of subarray we have 3 choices where the indices are 3,4,5. 
So total possible ways are 4*3=12. We can't take starting index as 4 or 5 because if subarray starts we index 4 it means we are not including 3.

incase nse doesn't exist assign nse as n
and incase of pse -1

array = 1 4 6 7 3 7 8 1
index = 0 1 2 3 4 5 6 7
NSE   = 1 3 3 3 1 1 1 N
PSE   =-1 1 4 6 1 3 7 -1

for 3
nse index = 7
pse index = 0

left size = index - pse index = 4 - 0 = 4
right size = nse index - index = 7 - 4 = 3

contribution = 3*leftsize*rightsize


Handle Duplicates

index = 0 1
arr   = 1 1

nse   = 2 2
pse   = -1 -1

for index 0 : 1 * (1*2) = 2 which are [1] and [1,1]
for index 1: 1 * (2*1) = 2 which are [1] and [1,1]
But we already considered [1,1]

so we only consider it once 
front -> nse is correct
back -> for pse we consider equality ie. previous smaller or equal element then pse for 2nd 1 would be 0
by doing equal we say that left vala one is ans for [1,1]
ie. we exclude left vala 1 from subarrays with ans as right vala one
*/

#define m 1000000007
class Solution {
public:
    vector<int> nextSmallerElement(vector<int> &arr){
        int n=arr.size();

        stack<int> ms; // store index

        vector<int> nse(n);

        for(int i=n-1;i>=0;i--){
            while(!ms.empty() && arr[i]<=arr[ms.top()]){
                ms.pop();
            }

            if(ms.empty()){
                nse[i]=n;
            }else{
                nse[i]=ms.top();
            }

            ms.push(i);
        }

        return nse;
    }

    vector<int> previousSmallerEqualElement(vector<int> &arr){
        int n=arr.size();

        stack<int> ms;

        vector<int> pse(n);

        for(int i=0;i<n;i++){
            while(!ms.empty() && arr[i]<arr[ms.top()]){ // note here we use < since = elements would be considered valid
                ms.pop();
            }

            if(ms.empty()){
                pse[i]=-1;
            }else{
                pse[i]=ms.top();
            }

            ms.push(i);
        }

        return pse;
    }
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        
        vector<int> nse = nextSmallerElement(arr);
        vector<int> pse = previousSmallerEqualElement(arr);

        long long int sum=0;

        for(int i=0;i<n;i++){
            int left = (i-pse[i]);
            int right = (nse[i]-i);

            long long int subArrays = (left*right)%m;

            long long int contribution = ((arr[i]%m)*(subArrays%m))%m;

            sum = ((sum%m) + (contribution%m))%m;
        }
    

        return sum%m;
    }
};