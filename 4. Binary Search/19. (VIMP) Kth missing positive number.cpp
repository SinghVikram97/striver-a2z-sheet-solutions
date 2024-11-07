// https://leetcode.com/problems/kth-m%20issing-positive-number/description/


// O(N)
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        unordered_set<int> ms;
        for(int i=0;i<arr.size();i++){
            ms.insert(arr[i]);
        }

        int count=0;
        for(int i=1;;i++){
            if(ms.find(i)==ms.end()){
                count++;
                if(count==k){
                    return i;
                }
            }
        }
    }
};

/*
brute force

assume you have an empty array and we have some k value, say k = 4the missing number, so in this case the missing value would be 4

Case 1:- where the value at a index in the array < k
now just consider the empty array again and we added a number smaller than k to it, say 2,
so now when we again try to find the 4th missing number we would get it as 5 ( as 1 3 4 5 , as 2 already present in the array, 
hence the missing value shifts by one position ahead and 5 is the 4th missing value), 
hence whenever we get a number in the array smaller than k, the kth missing value shifts by position ahead

Case2 :- where value at a index in array > k

now consider empty array again and we added a number greater than k,
assume k = 4 and we added 7 to it, here the kth missing element will be 4 itself, 
as even though seven was added - it indicated that the array might or might not contain the first 6 numbers and as the k = 4 
value is lesser than 7, so this kth value would also come under missing value, and as 7 > k, so no effect on k occur. So k is the missing element


k=4
[] ans=4

k=4
[2] ans=5 since 2 which is smaller than k=4 present so missing number shifts by 1

k=4
[7] ans=4 adding a number > k doesn't impact 

k=4
[4] ans=5, adding a number=k also shifts missing number by 1

*/


class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n=arr.size();

        for(int i=0;i<n;i++){
            if(arr[i]<=k){
                k++; // shift by one
            }else{
                return k;
            }
        }
        return k;
    }
};

// Binary Search
/*
[2,3,4,7,11]
 0 1 2 3 4

ideally at i=3 there should have been 4 so missing numbers before 7 = 7 - (i+1) = 7-4 = 3 (1,5,6)
similary for others

missing numbers: [1,1,1,3,6]

[2,3,4,7,11]
 0 1 2 3 4
[1,1,1,3,6]

now k=5
we want 2 indexes where k b/w count of missing numbers
ie. 7 and 11 since k b/w 3 and 6

so if missing of mid < k move right
else move left

now at end left would be at 11 and right would be at 7 ie. reverse

and answer would be arr[right]+more where more=k-missing 
3 numbers are missing till 7 we want 2 more to be 5

ans=arr[right]+k-missing 

now missing is just arr[right]-(right+1)

so

ans=arr[right]+k-(arr[right]-right-1)
ans=arr[right]+k-arr[right]+right+1
ans=k+right+1

or

ans=k+low (since low ahead of right by 1)


We use k+low because

[4,7,11]
k=3

here low would be 0
and high would be -1

so ans=3+0=3

*/
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n=arr.size();

        int left=0;
        int right=n-1;

        while(left<=right){
            int mid=(left+right)/2;

            int missing = arr[mid]-(mid+1);

            if(missing<k){
                // move right
                left=mid+1;
            }else{
                // move left
                right=mid-1;
            }
        }

        return left+k;
    }
};