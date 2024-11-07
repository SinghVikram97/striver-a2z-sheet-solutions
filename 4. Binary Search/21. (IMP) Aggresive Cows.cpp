// https://www.spoj.com/problems/AGGRCOW/
#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long int

// is possible to place these number of cows at this minimum distance
bool isPossible(vector<ll> &v, int numCows, int minDistance){
	ll n=v.size();
	
	ll cowsPlaced=1;
	ll prevPosition=0;
	for(ll i=1;i<n;i++){
		if(v[i]-v[prevPosition]>=minDistance){
			// can place
			cowsPlaced++;
			if(cowsPlaced>=numCows){
				return true; // early exit
			}
			prevPosition=i;
		}else{
			continue;
		}
		
	}
	
	return false;
	
}
int main() {
	ll t;
	cin>>t;
	while(t--){
		ll numStalls, numCows;
		cin>>numStalls>>numCows;
		
		vector<ll> v(numStalls);
		for(ll i=0;i<numStalls;i++){
			cin>>v[i];
		}
		
		// sort stall position
		sort(v.begin(), v.end());
		
		ll maxDistance=v[numStalls-1]-v[0]; // if there are 2 cows they can put at left and right extremes
		
		ll minDistance=1;
		
		ll start=minDistance;
		ll end=maxDistance;
		ll ans=-1;
		while(start<=end){
			ll mid=start+(end-start)/2;
			
			if(isPossible(v, numCows, mid)){
				// increase minimum distance
				start=mid+1;
				ans=mid;
			}else{
				// decrease minimum distance
				end=mid-1;
			}
		}
		
		cout<<ans<<endl;

	}
	return 0;
}