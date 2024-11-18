// https://leetcode.com/problems/largest-odd-number-in-string/description/

// Brute force
// 2 loops - an odd number must end with an odd number

// TLE
class Solution {
public:
    // returns true if s1>s2
    long long int compareNum(string &s1, string &s2){
        int n1=s1.length();
        int n2=s2.length();

        if(n1>n2){
            return true;
        }else if(n1<n2){
            return false;
        }else{
            for(int i=0;i<n1;i++){
                if((s1[i]-'0')>(s2[i]-'0')){
                    return true;
                }else if((s1[i]-'0')<(s2[i]-'0')){
                    return false;
                }else{
                    continue;
                }
            }
        }
        return false;
    }
    string largestOddNumber(string num) {
        int n=num.size();
        string ans="";
        for(int i=0;i<n;i++){
            string temp="";
            for(int j=i;j<n;j++){
                temp+=num[j];
                if((num[j]-'0')%2!=0){
                    if(compareNum(temp, ans)){
                        ans=temp;
                    }
                }
            }
        }
        return ans;
        
    }
};

// First odd number from last , string from start to first odd number from end
class Solution {
public:
    string largestOddNumber(string num) {
        int n=num.length();

        int index=-1;
        for(int i=n-1;i>=0;i--){
            if((num[i]-'0')%2!=0){
                index=i;
                break;
            }
        }
        if(index==-1){
            return "";
        }else{
            return num.substr(0, index+1);
        }
    }
};