// string to integer
// https://leetcode.com/problems/string-to-integer-atoi/
class Solution {
public:
    int myAtoi(string s) {
        int n=s.length();

        int i=0;

        long long int ans=0;
        int sign=1;
        bool started=false;

        while(i<n){
            while(i<n && s[i]==' ' && !started){
                i++;
            }

            if(isdigit(s[i])){
                ans=(ans*10)+(s[i]-'0');
                if(sign==-1 && ans*sign<INT_MIN){
                    return INT_MIN;
                }else if(sign==1 && ans*sign>INT_MAX){
                    return INT_MAX;
                }
                started=true;
            }else{
                if(started){
                    break;
                }
                if(s[i]=='-'){
                    sign=-1;
                }else if(s[i]=='+'){
                }else{
                    break;
                }
                started=true;
            }

            i++;
        }

        
        return ans*sign;
    }
};