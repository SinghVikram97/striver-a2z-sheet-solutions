// https://leetcode.com/problems/largest-rectangle-in-histogram/description/

/*
Each element bounded by the smallest element on both its sides
if a smaller element appears it breaks the rectangle
*/


class Solution {
public:
    vector<int> nextSmallerElement(vector<int> &v){
        int n=v.size();

        stack<int> ms;
        vector<int> ans(n); // stores index of nge

        for(int i=n-1;i>=0;i--){
            while(!ms.empty() && v[i]<=v[ms.top()]){
                ms.pop();
            }

            if(ms.empty()){
                ans[i]=n;
            }else{
                ans[i]=ms.top();
            }

            ms.push(i);
        }

        return ans;
    }

    vector<int> previousSmallerElement(vector<int> &v){
        int n=v.size();

        stack<int> ms;
        vector<int> ans(n); // stores index of nge

        for(int i=0;i<n;i++){
            while(!ms.empty() && v[i]<=v[ms.top()]){
                ms.pop();
            }

            if(ms.empty()){
                ans[i]=-1;
            }else{
                ans[i]=ms.top();
            }

            ms.push(i);
        }

        return ans;
    }

    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();

        vector<int> pse=previousSmallerElement(heights);
        vector<int> nse=nextSmallerElement(heights);

        int ans=INT_MIN;
        for(int i=0;i<n;i++){
            int right=nse[i]-i;
            int left=i-pse[i];

            int total=right+left-1;

            ans=max(ans, heights[i]*total);
        }

        return ans;
    }
};