// https://leetcode.com/problems/roman-to-integer/submissions/
class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int> mp;
        mp['I']=1;    
        mp['V']=5;  
        mp['X']=10;  
        mp['L']=50;  
        mp['C']=100;    
        mp['D']=500;  
        mp['M']=1000;  

        int n = s.length();

        int number=0;
        for(int i=0;i<n;i++){
            if(i+1<n){
                if(s[i]=='I'){
                    if(s[i+1]=='V'){
                        number+=4;
                        i++;
                    }else if(s[i+1]=='X'){
                        number+=9;
                        i++;
                    }else{
                        number+=mp[s[i]];
                    }
                }else if(s[i]=='X'){
                    if(s[i+1]=='L'){
                        number+=40;
                        i++;
                    }else if(s[i+1]=='C'){
                        number+=90;
                        i++;
                    }else{
                        number+=mp[s[i]];
                    }
                }else if(s[i]=='C'){
                    if(s[i+1]=='D'){
                        number+=400;
                        i++;
                    }else if(s[i+1]=='M'){
                        number+=900;
                        i++;
                    }else{
                        number+=mp[s[i]];
                    }
                }else{
                    number+=mp[s[i]];
                }
            }else{
                number+=mp[s[i]];
            }
        }

        return number;
    }
};