// https://practice.geeksforgeeks.org/problems/generate-all-binary-strings/1
class Solution{
public:
    void generateBinaryStrings(int num){
        vector<string> ans = generate(num);
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }
    }

    vector<string> generate(int num) {
        if(num==1){
            return {"0","1"};
        }

        vector<string> prev = generate(num-1);

        vector<string> ans;
        for(int i=0;i<prev.size();i++){
            if(prev[i].back()=='0'){
                ans.push_back(prev[i]+"0");
                ans.push_back(prev[i]+"1");
            }else{
                ans.push_back(prev[i]+"0");
            }
        }

        return ans;
    }


};