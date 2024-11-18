// https://leetcode.com/problems/sort-characters-by-frequency/description/

// Brute 
// Store characters and freq
// Push into priority queue by freq,char

// Note: map sorted on basis of key ie. character we want to sort on basis of value so that's why we used priority queues

// TC: 
/*
freq counting: O(N)
Pushing to priority queue: O(k*logk) [k unique characters each insertion takes logk time]
Building the result: O(N) popping: O(logk) for pop and building the result O(k)-> O(k*(logk+k))-> O(k*k)
So TC: O(N^2) if k close to N
*/
class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> mp;
        int n=s.length();

        for(int i=0;i<n;i++){
            mp[s[i]]++;
        }

        priority_queue<pair<int,char> > pq;
        for(auto it=mp.begin();it!=mp.end();it++){
            if(it->second!=0){
                pq.push(make_pair(it->second, it->first));
            }
        }

        string ans="";
        while(!pq.empty()){
            pair<int,char> topEle=pq.top();
            pq.pop();

            for(int i=0;i<topEle.first;i++){
                ans+=topEle.second;
            }
        }

        return ans;
    }
};


// O(N)
// Using counting sort
// But we have both a and A
// ASCII values 0 to 255
/*
Digits: 0-9: 48-57
UpperCase letters: A-Z: 65-90
LowerCase letters: a-z: 97-122
*/

/*
A=[ 2, 3, 0, 2, 3, 2]

maxValue = 3 so initialize array with size maxValue+1 ie. size 4

countArray=[0,0,0,0]

fill count array index=3 indicates value 3

countArray=[1,0,3,2]
index       0 1 2 3

Now traverse the countArray and construct ans
1 zeroes
0 ones
3 twos
2 threes
TC=O(n+K) where n number of values and k range of values

In this case we have characters then we store their frequency in an array freq array of size 256
and we need to sort this freq array

so it will look something like

0 1 2 2 1 0 1 3 2 3
0 1 2 3 4 5 6 7 8 9 .... 255
a b c d e f g h i j

We take buckets equal to maxFreq let's say 10
so counting array will be:
2 3 3
0 1 2 3 4 5 6 7 8 9 10 11

now typically ans would 0 0 1 1 1 2 2 2 
but instead we have to render characters so we store characters here so

while forming counting array:

  b cd 
0 1 2 3 4 5 6 7 8 9 10 11

as c has freq 2 we store it at index 2
now d also has freq 2 so we also store it at index 2

and then while forming ans we do b cc dd [ie. at index 2 double the char]

as we want in decreasing order traverse from right
*/
class Solution {
public:
    string frequencySort(string s) {
        vector<int> freq(256,0);
        int n=s.length();

        int maxFreq=0;
        for(int i=0;i<n;i++){
            freq[(int)s[i]]++;
            maxFreq=max(maxFreq, freq[(int)s[i]]);
        }
        
        // we store characters in our bucket
        vector<string> buckets(maxFreq+1,"");

        for(int i=0;i<256;i++){
            if(freq[i]>0){
                buckets[freq[i]]+=char(i);
            }
        }
        string ans="";
        for(int i=maxFreq;i>=0;i--){
            string currentString=buckets[i];
            for(int j=0;j<currentString.length();j++){
                for(int k=0;k<i;k++){
                    ans+=currentString[j]; // IMP: ans=ans+currentString[j] would give memory limit exceeded
                }
            }
        }

        return ans;
    }
};