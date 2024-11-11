// https://www.geeksforgeeks.org/problems/row-with-max-1s0023/1

// O(m*n) -> traverse using 2 loops
// O(mlogn) -> for each row find first occurrence of 1 (using binary search) and row with least value contains most ones

// O(m+n)

/*
start from top right corner

if it is 1 then we go left to check if there are more ones
if it is 0 then we go down since no 1s possible for this row towards left

for each row we store the leftmost position of one
and row with minimum leftmost position will be our ans
*/

/*

Doubt why don't we need to check to the right for next rows
for example
0 0 1 1
0 0 0 1
0 1 1 1 


here we move to 2nd col for 1st row
then we move down
then we move down 
wer are in 3rd row now if we find one it means all elements to right would also be 1
so we update our ans else we don't
*/
class Solution {
  public:
    int rowWithMax1s(vector<vector<int> > &arr) {
        int m=arr.size();
        int n=arr[0].size();
        
        int i=0;
        int j=n-1;
        
        int ans=-1;
        
        while(i<m && j>=0){
            if(arr[i][j]==1){
                ans=i;
                // move left
                j--;
            }else{
                // 0 so move down
                i++;
            }
        }
        return ans;
    }
};