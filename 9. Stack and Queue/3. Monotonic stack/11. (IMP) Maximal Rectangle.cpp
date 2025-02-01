// https://leetcode.com/problems/maximal-rectangle/description/

// Built on top of previous question

/*
For each row we find the largest rectangle in histogram
The height for each row will be determined by element on top
for example mat[1][2] is 1
and mat[0][2] is also 1

then height for mat[1][2] will be considered 2 for histogram calculation
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
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        
        vector<vector<int> > heights(m+1, vector<int> (n,0));

        int ans=-1;
        for(int i=0;i<m;i++){
            // calculate height array for row i
            // will be stored in heights[i+1] as for 1st row previous heights will be always zero
            for(int j=0;j<n;j++){
                if(matrix[i][j]=='1'){
                    heights[i+1][j]=1+heights[i][j];
                }else{
                    // store 0
                    heights[i+1][j]=0;
                }
            }

            // calculate maxRectangle for this heights array
        
            int largestRectangleCurRow = largestRectangleArea(heights[i+1]);
            
            ans=max(ans, largestRectangleCurRow);
        }

        return ans;

    }
};