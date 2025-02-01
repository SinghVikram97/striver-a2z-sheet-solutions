//https://practice.geeksforgeeks.org/problems/largest-element-in-array4009/0
int largest(vector<int> &arr, int n)
{
    int maxi=-1;
    for(int i=0;i<n;i++) {
        maxi=max(maxi, arr[i]);
    }
    return maxi;
}

// Time - O(N)
// Space - O(1)