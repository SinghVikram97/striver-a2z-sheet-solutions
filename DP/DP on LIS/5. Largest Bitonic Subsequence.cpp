// https://www.codingninjas.com/studio/problems/longest-bitonic-sequence_1062688
// answer would be longest increasing subsequence ending at i +
// longest descreasing subsequence starting at i
int longestBitonicSubsequence(vector<int>& arr, int n)
{
	// lis ending at i
	vector<int> dp1(n,0);

	for(int i=0;i<n;i++){
		dp1[i]=1;
		for(int j=i-1;j>=0;j--){
			if(arr[j]<arr[i]){
				dp1[i]=max(dp1[i],1+dp1[j]);
			}
		}
	}

	// lds starting at i
	vector<int> dp2(n,0);
	for(int i=n-1;i>=0;i--){
		dp2[i]=1;
		for(int j=i+1;j<n;j++){
			if(arr[j]<arr[i]){
				dp2[i]=max(dp2[i],1+dp2[j]);
			}
		}
	}

	int maxi=-1;
	for(int i=0;i<n;i++){
		// lis ending at i + lds starting at i - 1 (2 times)
		// only lis ending i
		// or only lds start at i
		maxi=max({maxi,dp1[i],dp2[i],(dp1[i]+dp2[i]-1)});
	}
	return maxi;
}

