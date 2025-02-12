// https://leetcode.com/problems/pascals-triangle/description/
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int> > ans(numRows); 

        for(int i=0;i<numRows;i++){
            if(i==0){
                ans[i].push_back(1);
            }else if(i==1){
                ans[i]={1,1};
            }else{
                vector<int> temp(i+1); // i=2 means 3rd row
                temp[0]=1;
                temp[i]=1;

                for(int j=1;j<i;j++){
                    temp[j]=ans[i-1][j-1]+ans[i-1][j];
                }

                ans[i]=temp;
            }
        }

        return ans;
    }
};