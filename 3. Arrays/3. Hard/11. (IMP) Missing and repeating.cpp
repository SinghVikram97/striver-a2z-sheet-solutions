// https://www.geeksforgeeks.org/problems/find-missing-and-repeating2512/1

/*
Treat numbers in array as indexes and mark indexes by increase them by (n+1)
If we see we are visiting an index twice ie. it has already been increased it is the repeated number

What about missing number -> traverse from start again if an index untouched it is missing number

since numbers in range [1,n] we decrease one from number for index calculation
*/
class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        int n=arr.size();
        int increaseBy=n+1;

        int a,b; 
        for(int i=0;i<n;i++){
            int index=(arr[i]%increaseBy)-1;

            if(arr[index]>n){
                // visited
                b=index+1; // +1 for number [1,n]
            }

            arr[index]+=increaseBy;
        }      

        for(int i=0;i<n;i++){
            if(arr[i]<=n){
                a=i+1;
            }
        }

        return {b,a};
    }
};