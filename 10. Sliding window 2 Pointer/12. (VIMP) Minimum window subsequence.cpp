// https://www.naukri.com/code360/problems/minimum-window-subsequence_2181133

// In prev question we only had to find a window in which every character of t was in s
// order didn't matter 

// Here we have to find minimum length substring in which t is a subsequence of s

/*
zbcabcdebdde
bde

according to previous ans can be deb since it contains all characters of t

for this one ans should be bcde
*/


// Before that:

// Check if a string subsequence of other string
// https://leetcode.com/problems/is-subsequence/description/
class Solution {
public:
    bool isSubsequence(string s, string t) {
       int i=0; // for t
       int j=0; // for s

       while(i<t.length() && j<s.length()){
          while(i<t.length() && t[i]!=s[j]){
            i++;
          }

          if(i==t.length()){
            return false;
          }else{
            j++;
            i++;
          }
       }

       if(j==s.length()){
        return true;
       }else{
        return false;
       }
    }
};

// Back to the question
// Brute force check for every substring if that substring contains t as a subsequence
// This checks if s subsequence of t

// Time complexity - O(n3) - O(n2 for substring) and O(n) for checking if subsequence
bool isSubsequence(string s, string t) {
       int i=0; // for t
       int j=0; // for s

       while(i<t.length() && j<s.length()){
          while(i<t.length() && t[i]!=s[j]){
            i++;
          }

          if(i==t.length()){
            return false;
          }else{
            j++;
            i++;
          }
       }

       if(j==s.length()){
        return true;
       }else{
        return false;
       }
    }

string minWindow(string s, string t)
{	
	int n1=s.length();
	int n2=t.length();

	int minLength=INT_MAX;
	string ans="";

	for(int i=0;i<n1;i++){
		string temp="";
		for(int j=i;j<n1;j++){
			temp+=s[j];

			if(isSubsequence(t, temp)){
				if(temp.length()<minLength){
					ans=temp;
					minLength=temp.length();
				}
			}
		}
	}

	return ans;
}


// Optimized
/*
Find a valid window, then start again from end of t till you find t again
This will be the shortest window 
Do this for every start char 
TC: O(S*T) where S and T length of both strings
*/

string minWindow(string s, string t)
{
	int n1=s.length();
  int n2=t.length();

  int i=0;
  int j=0;

  int minLength=s.length()+1;
  string ans="";

  while(i<n1){
     if(s[i]==t[j]){
       i++;
       j++;

       if(j==n2){
          // start from right to left
          int end=i-1; // point where equal since we incremented i to next
          i--;

          // make j start at end
          j--;

          // since we are sure we traverse from left to right we can go right to left
          while(j>=0){
              if(s[i]==t[j]){
                j--;
              }
              i--;
          }

          // At this point we have matched j again and i is at one left of equal character
          i++; 

          int length=end-i+1;

          if(length<minLength){
            minLength=length;
            ans=s.substr(i, length);
          }

          // now j at -1 make it 0 for again comparing
          j++;
          // as for i make it end+1 (wrong ans for: dynamicprogramming mm)
          // expected: mm
          // output: micprogram

          // as i+1 can also be a start of a window
          i++;
       }

     }else{
       i++;
     }
  }
  return ans;
}