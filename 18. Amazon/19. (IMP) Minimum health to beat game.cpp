// https://leetcode.com/problems/minimum-health-to-beat-game/description/
class Solution {
public:
    long long minimumHealth(vector<int>& damage, int armor) {
        long long maxi=-1;
        int n=damage.size();
        long long sum=0;

        for(int i=0;i<n;i++){
            maxi=max<long long>(maxi, damage[i]);
            sum+=damage[i];
        }

        sum=sum-maxi;
        
        // take maximum with armor
        int take=max<long long>(0, maxi-armor); // since armor can be more than maxi [2,5,3,4] and armor = 7

        sum+=take;

        return sum+1;
    }
};