// https://leetcode.com/problems/trapping-rain-water/description/

// for each element the rain water trapped in min(maxLeft, maxRight)
// ie. it is bounded by the maximum element on either side note: max not next greater
class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();

        vector<int> left(n); // stores max left
        vector<int> right(n); // stores max right

        int maxLeft=-1;
        for(int i=0;i<n;i++){
            maxLeft=max(maxLeft, height[i]); // include element itself as it will be zero when we calculate final ans 
            // if no greater element on either side
            left[i]=maxLeft; 
        }

        int maxRight=-1;
        for(int i=n-1;i>=0;i--){
            maxRight=max(maxRight, height[i]);
            right[i]=maxRight;
        }

        int contribution=0;

        for(int i=0;i<n;i++){
            contribution+=min(left[i],right[i])-height[i];
        }

        return contribution;
    }
};

// Optimised space

// WE keep 2 pointers left and right
/*
if left < right
we move left ++ and calculate for that left using maxLeft

else if right < left
we move right -- and calculate for that right using maxRight


Why?

left and right pointer to the value which is max till now ie. out of left and right whichever is minium we move it

so if we find left < right
so we know maxLeft(previous lefts) would be less than or equal to arr[right]
if they would have been greater we would have stayed there and right would have moved

so ans at current left capped by maxLeft
*/
class Solution {
public:
    int trap(vector<int> &height) {
        
        int n=height.size();
        
        int max_left=0;  // As 0 is the least height possible
        int max_right=0;
        
        int left=0;
        int right=n-1;
        
        int ans=0;
        
        while(left<=right){
            
            // It means a greater building on the right exists
            if(height[left]<height[right]){
                
                // It means covered by max_left from left side
                if(height[left]<max_left){
                    ans=ans+(max_left-height[left]);  
                }
                // Not covered from left so update max_left
                else{
                    max_left=height[left];
                }
                left++;                
            }
            // height[right]<height[left]
            // It means a greater building on the left exists
            else{
                
                if(height[right]<max_right){
                    ans=ans+(max_right-height[right]);
                }
                else{
                    max_right=height[right];
                }
                right--;                
            }
        }
        return ans;       
        
    }
};