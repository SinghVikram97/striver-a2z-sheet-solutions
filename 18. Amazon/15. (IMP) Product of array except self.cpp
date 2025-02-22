// https://leetcode.com/problems/product-of-array-except-self/
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();

        int totalProduct=1;
        int countZero=0;
        for(int i=0;i<n;i++){
            if(nums[i]!=0){
                totalProduct*=nums[i];
            }else{
                countZero++;
            }
        }

        vector<int> ans(n,0);
        if(countZero>1){
            return ans;
        }else if(countZero==1){
            for(int i=0;i<n;i++){
                if(nums[i]==0){
                    ans[i]=totalProduct;
                    return ans;
                }
            }
        }else{
            for(int i=0;i<n;i++){
                ans[i]=totalProduct/nums[i];
            }
            return ans;
        }

        return ans;
    }
};

// Other solution
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> product(n);

        int prefix=1;
        for(int i=0;i<n;i++){
            product[i]=prefix;
            prefix=prefix*nums[i];
        }

        int suffix=1;
        for(int i=n-1;i>=0;i--){
            product[i]=product[i]*suffix;
            suffix=suffix*nums[i];
        }

        return product;
    }
};