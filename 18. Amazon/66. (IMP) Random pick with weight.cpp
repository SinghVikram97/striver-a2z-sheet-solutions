// https://leetcode.com/problems/random-pick-with-weight/description/

/*
Problem better explained:
Given an array w of size N.
There are N numbers from 0 to N-1.
Probability of choosing a number i from [0,N-1] is P(i) = w[i]/sum(w).
You need to write a function(pickIndex) which will pick an element from [0,N-1] based on probabilities defined above.
Note:

In uniform random selection probability, P(i) would be 1/N.
And also the problem does not has unique solution because we are choosing an element at random. 
So the correctness of the solution might be calculated based on the distrubtion of the numbers returned by your function.

Let us look at a simple example. Given an input list of values [1, 9], 
when we pick up a number out of it, the chance is that 9 times out of 10 we should pick the number 9 as the answer.
*/

// Brute force would be to distribute the numbers
// for example above [1, 9, 9....9] 9 times
// and keep a rolling index
// But too much space

/*
say we have the numbers 1, 5, 2 easiest solution is to construct the following array
arr[] = {0,1,1,1,1,1,2,2}
then generate a random number between 0 and 7 and return the arr[rnd]. 
This is solution is not really good though due to the space requirements it has (imagine a number beeing 2billion).
*/

/*
arr
0 1 1 1 1 1 2 2
0 1 2 3 4 5 6 7

arr[0] which represents index 0
arr[1-5] represents index 1
arr[6-7] represents index 2

So instead of laying out the array we use prefix sum
[1,5,2] = [1,6,8]

Now we pick a random integer in range of [1,8] 

Now we can easily solve this by searching for number just bigger for example random number is 7
we search through [1,6,8]
and then number would by 8 ie. number just greater or equal
so we return index 2 which is index at which 8 is
*/
class Solution {
public:
    vector<int> prefixSum;
    Solution(vector<int>& w) {
        int n=w.size();
        prefixSum.push_back(w[0]);
        for(int i=1;i<n;i++){
            prefixSum.push_back(w[i]+prefixSum.back());
        }
    }
    
    int justGreaterEqual(int num){
        int start=0;
        int end=prefixSum.size()-1;

        int ans=-1;
        while(start<=end){
            int mid=(start+end)/2;

            if(prefixSum[mid]>=num){
                ans=mid;
                // move left
                end=mid-1;
            }else{
                start=mid+1;
            }
        }

        return ans;
    }

    int pickIndex() {
        // pick a random number b/w 1 to totalSum 
        int totalSum=prefixSum.back();
        int randIndex = (rand()%totalSum)+1;
        return justGreaterEqual(randIndex);
    }
};

// or we can pick random number b/w 0 to totalSum-1
// and then do justGreaterEqual(randIndex+1)

// when we lay numbers with weight
// 0 1 1 1 1 1 2 2
// 0 1 2 3 4 5 6 7
// prefix sum = [1,6,8]
// random number b/w 0 to 7
// since number exclusive ie. 1 ,6, 8 mark starting of new number
// we have to find element just greater so we can change in binary search to >
// and then use the same without randIndex+1

class Solution {
public:
    vector<int> prefixSum;
    Solution(vector<int>& w) {
        int n=w.size();
        prefixSum.push_back(w[0]);
        for(int i=1;i<n;i++){
            prefixSum.push_back(w[i]+prefixSum.back());
        }
    }
    
    int justGreaterEqual(int num){
        int start=0;
        int end=prefixSum.size()-1;

        int ans=-1;
        while(start<=end){
            int mid=(start+end)/2;

            if(prefixSum[mid]>num){
                ans=mid;
                // move left
                end=mid-1;
            }else{
                start=mid+1;
            }
        }

        return ans;
    }

    int pickIndex() {
        // pick a random number b/w 1 to totalSum 
        int totalSum=prefixSum.back();
        int randIndex = rand()%totalSum;
        return justGreaterEqual(randIndex);
    }
};
