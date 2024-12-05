// https://leetcode.com/problems/candy/

// 2 pass
// First from left to right -> ensure child has candy more than it's left neighbour
// Then from right to left -> ensure child has candy more than it's right neighbour

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n=ratings.size();

        vector<int> candies(n, 1);

        for(int i=1;i<n;i++){
            if(ratings[i]>ratings[i-1] && candies[i]<=candies[i-1]){
                candies[i]=candies[i-1]+1;
            }
        }

        for(int i=n-2;i>=0;i--){
            if(ratings[i]>ratings[i+1] && candies[i]<=candies[i+1]){
                candies[i]=candies[i+1]+1;
            }
        }

        int sum=0;
        for(int i=0;i<candies.size();i++){
            sum=sum+candies[i];
        }
        return sum;
    }
};