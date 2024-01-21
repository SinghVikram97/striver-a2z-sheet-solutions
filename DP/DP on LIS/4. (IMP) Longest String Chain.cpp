// https://leetcode.com/problems/longest-string-chain/description/
// Same as LIS
// Sort by length - see lambda
class Solution {
public:
    bool isPredecessor(string a, string b){
      // a="a" and b="b" not predecessor
      if(a.length()+1!=b.length()){
        return false;
      }
      // b>a in length
      int i=0;
      int j=0;
      bool unequal=false;
      while(i<a.length() && j<b.length()){
        if(a[i]==b[j]){
          i++;
          j++;
        }
        else{
          if(unequal){
            return false;
          }else{
            // assume we inserted a character in a
            // that char = b[j]
            j++;
            unequal=true;
          }
         
        }
      }


      // 2 cases
      // abc , abac
      // handled case a,b at start
      if(i==a.length() && j==b.length()){
        return true;
      }
      // abc , abcc
      if(i==a.length() && j==b.length()-1 && !unequal){
        return true;
      }

      return false;
      
    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),[](string a, string b){
          return a.size() < b.size();
        });

        for(int i=0;i<words.size();i++){
          cout<<words[i]<<"  ";
        }
        cout<<endl;

        int n=words.size();
        vector<int> dp(n);

        for(int i=n-1;i>=0;i--){
          dp[i]=1;
          for(int j=i+1;j<n;j++){
             if(isPredecessor(words[i],words[j])){
                dp[i]=max(dp[i],1+dp[j]);
             }
          }
        }

        int maxi=-1;
        for(int i=0;i<n;i++){
            maxi=max(maxi,dp[i]);
        }
        return maxi;
    }
};

