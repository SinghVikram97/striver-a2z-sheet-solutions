// https://leetcode.com/problems/analyze-user-website-visit-pattern/description/

// IMP: Note & when sorting because it makes a copy while traversing , we want to modify original array
// TLE
class Solution {
public:
    vector<string> mostVisitedPattern(vector<string>& username, vector<int>& timestamp, vector<string>& website) {
        // separate visits per user
        unordered_map<string, vector<pair<int, string > > > mp;

        int n=username.size();

        for(int i=0;i<n;i++){
            mp[username[i]].push_back({timestamp[i],website[i]});
        }

        // sort visits by timestamp for every user
        for(auto &it:mp){
            sort(it.second.begin(), it.second.end());
        }

        // store for every user every possible 3 sequences (note subsequences not subarray)
        // store it in a set
        // username -> set of visits
        unordered_map<string, unordered_set<string> > visited;
        unordered_set<string> uniqueOrders;
        for(auto it:mp){
            vector<pair<int, string > > visits=it.second;

            for(int i=0;i<visits.size();i++){
                for(int j=i+1;j<visits.size();j++){
                    for(int k=j+1;k<visits.size();k++){
                        string joinVisit = visits[i].second+"#"+visits[j].second+"#"+visits[k].second;
                        visited[it.first].insert(joinVisit);
                        uniqueOrders.insert(joinVisit);
                    }
                }
            }
        }

        // Now for every 3 sequence check its count
        int maxCount=0;
        string ans="";
        for(auto it:uniqueOrders){
            // check for each user
            int count=0;
            for(auto it1:visited){
                if(it1.second.find(it)!=it1.second.end()){
                    count++;
                }
            }
            cout<<it<<" "<<count<<endl;
            if(count>maxCount){
                ans=it;
                maxCount=count;
            }else if(count==maxCount){
                string possibleAns=it;
                if(ans==""){
                    ans=possibleAns;
                }else if(possibleAns<ans){
                    ans=possibleAns;
                }
                maxCount=count;
            }
        }

        // split string on #
        string temp="";
        vector<string> finalAns;
        for(int i=0;i<ans.length();i++){
            if(ans[i]!='#'){
                temp=temp+ans[i];
            }else{
                finalAns.push_back(temp);
                temp="";
            }
        }

        finalAns.push_back(temp);

        return finalAns;
    }
};

// Optimize calculate pattern count while generating subsequences
class Solution {
public:
    vector<string> mostVisitedPattern(vector<string>& username, vector<int>& timestamp, vector<string>& website) {
        // separate visits per user
        unordered_map<string, vector<pair<int, string > > > mp;

        int n=username.size();

        for(int i=0;i<n;i++){
            mp[username[i]].push_back({timestamp[i],website[i]});
        }

        // sort visits by timestamp for every user
        for(auto &it:mp){
            sort(it.second.begin(), it.second.end());
        }

        // store for every user every possible 3 sequences (note subsequences not subarray)
        // store it in a set
        // username -> set of visits
        unordered_map<string, unordered_set<string> > visited;
        unordered_map<string,int> patternCount;
        for(auto it:mp){
            vector<pair<int, string > > visits=it.second;
            unordered_set<string> uniquePatterns; // per user

            for(int i=0;i<visits.size();i++){
                for(int j=i+1;j<visits.size();j++){
                    for(int k=j+1;k<visits.size();k++){
                        string joinVisit = visits[i].second+"#"+visits[j].second+"#"+visits[k].second;
                        uniquePatterns.insert(joinVisit);
                    }
                }
            }

            for(const string &p:uniquePatterns){
                patternCount[p]++;
            }
        }

        // Find max count
        int maxCount=0;
        string ans="";

        for(auto it:patternCount){
            string pattern=it.first;
            int count=it.second;

            if(count>maxCount){
                ans=pattern;
                maxCount=count;
            }else if(count==maxCount){
                if(ans==""){
                    ans=pattern;
                }else if(pattern<ans){
                    ans=pattern;
                }
            }
        }

        // split string on #
        string temp="";
        vector<string> finalAns;
        for(int i=0;i<ans.length();i++){
            if(ans[i]!='#'){
                temp=temp+ans[i];
            }else{
                finalAns.push_back(temp);
                temp="";
            }
        }

        finalAns.push_back(temp);

        return finalAns;
    }
};