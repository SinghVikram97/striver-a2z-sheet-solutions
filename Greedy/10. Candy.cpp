// https://leetcode.com/problems/candy/description/

// Approach is Very Simple:-

// Firstly handle to right side Rating[i]>Rating[i+1]
// Then handle left side Now handle Rating[i-1]>Rating[i]

// One loop from the left to right
// Then from right to left
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n=ratings.size();
        vector<int> candies(n,1);

        for(int i=0;i<n-1;i++){
            if(ratings[i]>ratings[i+1] && candies[i]<=candies[i+1]){
                candies[i]=candies[i+1]+1;
            }
            else if(ratings[i]<ratings[i+1] && candies[i]>=candies[i+1]){
                candies[i+1]=candies[i]+1;
            }
        }

        for(int i=n-1;i>0;i--){
            if(ratings[i]>ratings[i-1] && candies[i]<=candies[i-1]){
                candies[i]=candies[i-1]+1;
            }
            else if(ratings[i]<ratings[i-1] && candies[i]>=candies[i-1]){
                candies[i-1]=candies[i]+1;
            }
        }

        int ans=0;
        for(int i=0;i<n;i++){
            ans+=candies[i];
        }
        return ans;
    }
};