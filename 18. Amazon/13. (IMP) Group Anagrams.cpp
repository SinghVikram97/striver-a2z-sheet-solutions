// https://leetcode.com/problems/group-anagrams/description/

// TC: O(N∗MLogM) since we are sorting N strings of length M
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& str) {
        int n=str.size();

        unordered_map<string, vector<string> > mp;
        for(int i=0;i<n;i++){
            string temp=str[i];
            sort(temp.begin(), temp.end());
            mp[temp].push_back(str[i]);
        }

        vector<vector<string> > ans;
        for(auto it=mp.begin();it!=mp.end();it++){
            ans.push_back(it->second);
        }

        return ans;
    }
};

// TIP: We can use counting sort to sort strings which will bring sorting complexity to O(M)
class Solution {
public:
    void sortC(string &temp){
        // 26 buckets with freq for each character
        vector<int> freq(26,0);

        int n=temp.size();

        for(int i=0;i<n;i++){
            freq[temp[i]-'a']++;
        }

        int index=0;
        for(int i=0;i<26;i++){
            while(freq[i]>0){
                temp[index]=char('a'+i);
                index++;
                freq[i]--;
            }
        }
    }
    vector<vector<string>> groupAnagrams(vector<string>& str) {
        int n=str.size();

        unordered_map<string, vector<string> > mp;
        for(int i=0;i<n;i++){
            string temp=str[i];
            sortC(temp);
            cout<<str[i]<<" "<<temp<<endl;
            mp[temp].push_back(str[i]);
        }

        vector<vector<string> > ans;
        for(auto it=mp.begin();it!=mp.end();it++){
            ans.push_back(it->second);
        }

        return ans;
    }
};