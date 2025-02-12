// https://www.interviewbit.com/problems/subarray-with-given-xor/


// Brute Force - O(n2) - TLE
int Solution::solve(vector<int> &A, int B) {
    int n=A.size();

    int ans=0;
    for(int i=0;i<n;i++){
        int cxor=0;

        for(int j=i;j<n;j++){
            cxor=cxor^A[j];

            if(cxor==B){
                ans++;
            }
        }
    }
    return ans;
}

// O(N)
/*
Example
Target XOR = 4^10^5
Current XOR = 4^10^5^2^3

We need a previous XOR = 2^3 
Since if we do current XOR ^ previous XOR = 4^10^5
since number ^ number = 0

So if we find TargetXor ^ CurrentXor in previous XORs then we have an answer
since TargetXor ^ CurrentXor = PreviousXor
*/
int Solution::solve(vector<int> &A, int B) {
    int n=A.size();

    unordered_map<int,int> mp;// xor , count
    mp[0]=1;
    
    int currentXor=0;
    int targetXor=B;
    int ans=0;
    for(int i=0;i<n;i++){
        currentXor=currentXor^A[i];
        int previousXor = targetXor^currentXor;
        ans=ans+mp[previousXor];
        mp[currentXor]++;
    }
    return ans;
}