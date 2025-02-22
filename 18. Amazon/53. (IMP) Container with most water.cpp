// https://leetcode.com/problems/container-with-most-water/description/

// TLE
class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int ans=-1;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                ans=max(ans,(min(height[i],height[j]))*(j-i));
            }
        }
        return ans;
    }
};

// O(N)
/*
Initially, we consider the area constituting the exterior most lines. 
Now, to maximize the area, we need to consider the area between the lines of larger lengths. 
If we try to move the pointer at the longer line inwards, we won't gain any increase in area, 
since it is limited by the shorter line. But moving the shorter line's pointer could turn out to be beneficial, 
as per the same argument, despite the reduction in the width. 
This is done since a relatively longer line obtained by moving the shorter line's pointer might overcome 
the reduction in area caused by the width reduction
*/
class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int start=0;
        int end=n-1;
        int ans=-1;
        while(start<end){
            if(height[start]<=height[end]){
                ans=max(ans,(end-start)*height[start]);
                start++;
            }else{
                ans=max(ans,(end-start)*height[end]);
                end--;
            }
        }

        return ans;
    }
};