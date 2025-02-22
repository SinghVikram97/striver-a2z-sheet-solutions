// https://practice.geeksforgeeks.org/problems/row-with-max-1s0023/1

// find index of first occurence of one and find row with smallest index
// Time - O(n*logn)
// We can optimse further by starting next row at startIndex-1 of current ans
class Solution{
public:

    int firstOccurrence(vector<int> &v,int start,int end,int target){
        int firstIndex=-1;
        while(start<=end){
            int mid = (start+end)/2;

            if(v[mid]==target){
                // update
                firstIndex=mid;
                // move left
                end=mid-1;
            }
            else if(target<v[mid]){
                // move left
                end=mid-1;
            }
            else{
                start=mid+1;
            }
        }
        return firstIndex;
    }

	int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
        int minFirstIndex=INT_MAX-5;
        int ans=-1;
	    for(int i=0;i<n;i++){
            int indexOfFirstOne=firstOccurrence(arr[i],0,m-1,1);
            if(indexOfFirstOne==-1){
                // No ones
            }
            else{
                if(indexOfFirstOne<minFirstIndex){
                    minFirstIndex=indexOfFirstOne;
                    ans=i;
                }
            }
        }
        return ans;
	}

};

// More optimised start at top right
class Solution {
  public:
    int rowWithMax1s(vector<vector<int>> &arr) {
        int m=arr.size();
        int n=arr[0].size();
        
        int i=0;
        int j=n-1;
        
        int ans;
        while(i<m && j>=0){
            if(arr[i][j]==1){
                // move left
                ans=i;
                j--;
            }else{
                // move down
                i++;
            }
        }
        return ans;
    }
};