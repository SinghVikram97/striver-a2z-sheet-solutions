// https://leetcode.com/problems/remove-k-digits/description/

// Can be done by recursion but TLE00
// You cannot rearrange the digits to form new number. You can just remove from existing order

// given a random sequence of digits when are they minimum 
/*
618942 
when sorted
124689 ie smaller number comes at larger decimal place

now 142
if we delete 1 we would get 4 in place of larger decimal place

keep 1
142

delete 4 its okay since we get 2 which is smaller than 4 in its place

145

here we don't delete 4 since we get 5 in its place

so we just have to maintain a monotonic stack increasing 

and if after traversing we can't remove k elements
remove them after from array

*/
class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<int> ms;

        for(int i=0;i<num.length();i++){
            int number = num[i]-'0';
            
            while(k>0 && !ms.empty() && number<ms.top()){
                ms.pop();
                k--;
            }
            
            // Avoid starting number as 0
            // Element at bottom of stack is the starting
            if(ms.empty() && number==0){
                continue;
            }

            ms.push(number);
        }

        while(k>0 && !ms.empty()){
                ms.pop();
                k--;
        }
        
        string ans="";

        while(!ms.empty()){
            int num=ms.top();
            ms.pop();

            ans.push_back(num+'0');
        }

        reverse(ans.begin(), ans.end());

        return ans == "" ? "0" : ans;
       
    }
};