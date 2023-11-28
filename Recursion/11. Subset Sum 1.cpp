// https://practice.geeksforgeeks.org/problems/subset-sums2234/1?

// take or don't take
class Solution
{
public:
    void printSum (vector<int> &v, int n, int i, int currentSum, vector<int> &ans) {

        if(i==n){
            ans.push_back(currentSum);
            return;
        }

        // take
        printSum(v,n,i+1,currentSum+v[i],ans);


        // don't take
        printSum(v,n,i+1,currentSum,ans);

    }
    vector<int> subsetSums(vector<int> arr, int N)
    {
      vector<int> ans;
       printSum(arr,N,0,0,ans);
       return ans;
    }
};