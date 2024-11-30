// https://leetcode.com/problems/minimum-window-substring/description/

// Brute force -> for each window check if substring contains t if it does try to lessen the window
// Gives TLE
class Solution {
public:
    bool checkEqual(unordered_map<char,int> &mp, unordered_map<char,int> &goal){
        for(auto it=goal.begin();it!=goal.end();it++){
            if(mp[it->first]<it->second){
                return false;
            }
        }
        return true;
    }
    string minWindow(string s, string t) {
        int sl=s.length();
        int tl=t.length();

        int left=0;
        int right=0;

        unordered_map<char,int> goal;

        for(int i=0;i<tl;i++){
            goal[t[i]]++;
        }

        unordered_map<char,int> mp;
        string ans=s+s;
        while(left<=right && right<sl){
            mp[s[right]]++;
            // check if both hashmaps equal
            bool bothEqual=checkEqual(mp, goal);

            if(bothEqual){
                // update ans
                if(right-left+1<ans.length()){
                    ans=s.substr(left, right-left+1);
                }

                // try to decrease window size
                while(left<=right && bothEqual){
                    mp[s[left]]--;
                    left++;

                    bothEqual=checkEqual(mp, goal);

                    if(bothEqual){
                        // update ans
                        if(right-left+1<ans.length()){
                            ans=s.substr(left, right-left+1);
                        }
                    }
                }
                
                if(left>right){
                    // try new window
                    right=left;
                }else if(!bothEqual){
                    // increase window
                    right++;
                }
            }else{
                // increase window
                right++;
            }
        }

        if(ans==s+s){
            return "";
        }else{
            return ans;
        }
    }
};


// Logic was correct just need to change how we check if a substring contains t
/*
n1 -> s
n2 -> t

We need to find n2 characters of t

Using one map we fill it will freq of characters of t

if freq of any char of t > 0 we increase counter 
also we decrease its freq irrespective if it was >0 or not but we only increase counter if it was >0

Now since we decrease counter even for other chars those chars which are not in t or which are more in freq than we expect in t
Freq of these chars will be -ve

Now when counter reaches n2 we try to make the window smaller how do we re-add characters of t to the map

We increment freq for the character we removed from the window
Now if its freq>0 we decrease counter

Characters which had -ve freq would only go till 0 in worst case so counter would remain the same
Thats how we handle comparison in just one map

And for other characters for ex T had 2 a's and we add 5 a's
for freq of a would be -3 so till we remove 3 a's from window we are fine
As soon as we remove 4th a , our freq becomes > 0 and we decrease counter so it longer satisfies the equality of substring=t

*/
class Solution {
public:
    string minWindow(string s, string t) {
        int n1=s.length();
        int n2=t.length();

        int left=0;
        int right=0;

        int minLength=INT_MAX-5;
        int minStart=-1;

        int counter=n2;

        unordered_map<char,int> mp;
        for(int i=0;i<n2;i++){
            mp[t[i]]++;
        } 

        while(left<=right && right<n1){
            if(mp[s[right]]>0){
                counter--;
            }

            mp[s[right]]--; // even if not matching decrease count

            if(counter>0){
                // move right
                right++;
            }else if(counter==0){
                // update ans
                int length=right-left+1;

                if(length<minLength){
                    minLength=length;
                    minStart=left;
                }

                // try to shorten the window
                while(left<=right && counter==0){
                    mp[s[left]]++; // ie. remove from window so it needs to be added again

                    if(mp[s[left]]>0){
                        counter++; // one character needs to be taken care of
                    }

                    left++;

                    if(counter==0){
                        // update ans
                        int length=right-left+1;

                        if(length<minLength){
                            minLength=length;
                            minStart=left;
                        }
                    }
                }

                if(left>right){
                    // restart window
                    right=left;
                }else if(counter!=0){
                    // move right
                    right++;
                }
            }
        }

        if(minStart==-1){
            return "";
        }
        return s.substr(minStart,minLength);
    }
};