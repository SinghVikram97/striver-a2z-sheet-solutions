// https://leetcode.com/problems/reorganize-string/

// IMP : By default C++ heap is a max heap
// To define custom max heap
// priority_queue<pair<char,int>, vector<pair<char,int> > , decltype(comp)> pq;
/*
auto comp = [](auto &a, auto &b){
            return a.second<b.second; // max heap
            Notice < we have for max heap
};
*/
class Solution {
public:
    string reorganizeString(string s) {
        int n=s.length();

        auto comp = [](auto &a, auto &b){
            return a.second<b.second; // max heap
        };
        priority_queue<pair<char,int>, vector<pair<char,int> > , decltype(comp)> pq;

        vector<int> freq(26,0);

        for(int i=0;i<n;i++){
            freq[s[i]-'a']++;
        }

        // Push to priority queue
        for(int i=0;i<26;i++){
            if(freq[i]>0){
                pq.push({char('a'+i), freq[i]});
            }
        }

        string ans="";
        pair<char,int> prevChar={'#', -1};

        for(int i=0;i<n;i++){
            // take out most frequent character
            if(pq.empty()){
                return "";
            }
            pair<char,int> topEle=pq.top();
            pq.pop();

            ans.push_back(topEle.first);

            // push prevChar again to priority queue, if its freq is > 0
            if(prevChar.first!='#' && prevChar.second>0){
                pq.push(prevChar);
            }

            // make current char as prevChar, make its freq less than 1
            prevChar={topEle.first, topEle.second-1};
        }

        return ans;
    }
};

// Without priority queue
/*
Lay the most frequent element into the string separated by one position
*/
class Solution {
public:
    string reorganizeString(string s) {
        int n=s.length();

        vector<int> freq(26,0);

        for(int i=0;i<n;i++){
            freq[s[i]-'a']++;
        }

        int maxFreq=-1;
        int indexMax;
        for(int i=0;i<26;i++){
            if(freq[i]>maxFreq){
                maxFreq=freq[i];
                indexMax=i;
            }
        }

        // maximum freq should be less than equal to (n+1)/2 
        if(maxFreq>(n+1)/2){
            return "";
        }

        // lay character with max freq first
        string ans(n, ' ');
        char ch=char('a' +indexMax);

        int i=0;
        while(maxFreq!=0){
            ans[i]=ch;
            i=i+2;
            maxFreq--;
        }

        // Now lay remaining characters at even index first and then odd
        for(int j=0;j<26;j++){
            if(freq[j]>0 && j!=indexMax){
                int maxFreq=freq[j];

                while(maxFreq!=0){
                    if(i>=n){
                        i=1;
                    }
                    ans[i]=char('a'+j);
                    maxFreq--;
                    i=i+2;
                }
            }
        }

        return ans;
    }
};