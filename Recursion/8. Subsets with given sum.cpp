// https://practice.geeksforgeeks.org/problems/perfect-sum-problem5633/1


// include in sum or don't -> 1st approach for subset, ie. check sum at last
// if we reach the target sum then increment count


// Check all subsets- O(2^n)

class Solution{
    public:
    long long int M = 10000007;
    void recursive(int arr[], int n, int i, int currentSum, int targetSum, int &count){
        if(i==n){
			if(currentSum==targetSum){
				count=((count%M)+1)%M;
			}
			return;
		}

		// take
		recursive(arr,n,i+1,currentSum+arr[i],targetSum,count);

		// don't take
		recursive(arr,n,i+1,currentSum,targetSum,count);
    }

	int perfectSum(int arr[], int n, int sum)
	{
		int count = 0;
		recursive(arr,n,0,0,sum,count);
		return count;
	}
   
};