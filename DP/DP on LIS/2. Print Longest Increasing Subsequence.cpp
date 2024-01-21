// https://www.codingninjas.com/studio/problems/printing-longest-increasing-subsequence_8360670
vector<int> printingLongestIncreasingSubsequence(vector<int> arr, int n) {
	vector<int> dp(n);

    for(int i=n-1;i>=0;i--){
        dp[i]=1;
        for(int j=i+1;j<n;j++){
            if(arr[j]>arr[i]){
                dp[i]=max(dp[i],1+dp[j]);
            }
        }
    }    
    
    int maxi=-1;
    int index=-1;
    for(int i=0;i<n;i++){
        if(dp[i]>maxi){
            maxi=dp[i];
            index=i;
        }
    }

    // starting with arr[index], one character we already know
    vector<int> ans;
    ans.push_back(arr[index]);
    int element=arr[index];
    int length=maxi-1; // length-1 as one with already know

    while(length>0){
		int maxi=-1;
        int nextElement=-1;
        int nextIndex=-1;
        // select the next element we would have picked which calculating lis
        for(int i=index+1;i<n;i++){
            if(arr[i]>element && dp[i]>maxi){
                nextElement=arr[i];
                maxi=dp[i];
                nextIndex=i;
            }
        }

        ans.push_back(nextElement);
        element=nextElement;
        index=nextIndex;
		length--;
    }
    return ans;
}
