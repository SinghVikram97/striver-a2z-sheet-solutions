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

// Using from back
vector<int> printingLongestIncreasingSubsequence(vector<int> arr, int n) {
	vector<int> dp(n);

    for(int i=0;i<n;i++){
        dp[i]=1;
        for(int j=i-1;j>=0;j--){
            if(arr[i]>arr[j]){
                dp[i]=max(dp[i],1+dp[j]);
            }
        }
    }

    int ans=-1;
    int indexMaxEnding;
    for(int i=0;i<n;i++){
        if(dp[i]>ans){
            ans=dp[i];
            indexMaxEnding=i;
        }
    }

    // we know ending
    vector<int> lis;
    lis.push_back(arr[indexMaxEnding]);
    int curIndex=indexMaxEnding;

    // ans is the length of lis
    while(lis.size()!=ans){
        int maxi=-1;
        int nextIndex=-1;

        // select element which can be picked
        for(int i=curIndex-1;i>=0;i--){
            if(arr[i]<arr[curIndex] && dp[i]>maxi){
                nextIndex=i;
                maxi=dp[i];
            }
        }
        lis.push_back(arr[nextIndex]);
        curIndex=nextIndex;
    }

    reverse(lis.begin(), lis.end());
    return lis;
    
}

// Using O(nlogn) solution
// [1, 7, 8, 3, 1, 4, 5]
/*
take 1 [1]
7>1 take 7 [1,7]
8>7 take 8 [1,7,8]
3<8 find position of 3 and replace with first element > 3 [1,3,8] 
1<8 find position of 1 and replace with first element >=1 or just ignore [1,3,8]
4<8 replace 8 with 4 [1,3,4]
5>4 [1,3,4,5]


*/
void replace(vector<int> &ans, int x, int index, vector<int> &indices, vector<int> &parent) {
    // replace num just greater than x with x
    int start = 0;
    int end = ans.size() - 1;

    int upperBound = -1;
    while (start <= end) {
        int mid = (start + end) / 2;

        if (ans[mid] == x) {
            // ignore
            return;
        } else if (x < ans[mid]) {
            // move left
            upperBound = mid;
            end = mid - 1;
        } else {
            // move right
            start = mid + 1;
        }
    }

    if (upperBound != -1) {
        ans[upperBound] = x;
        indices[upperBound] = index; // index in original array
        // one before in ans
        parent[index] = upperBound-1 >=0 ? indices[upperBound-1] : -1; 
    }
}
vector < int > printingLongestIncreasingSubsequence(vector < int > nums, int n) {
    vector<int> ans; 
    vector<int> indices; // index in original array of previously inserted element
    vector<int> parent(n,-1);

    for (int i = 0; i < n; i++) {
        if (ans.size() == 0) {
            ans.push_back(nums[i]);
            indices.push_back(i);
        } else {
            if (nums[i] > ans.back()) {
                ans.push_back(nums[i]);
                parent[i]=indices.back();
                indices.push_back(i);
            } else {
                // replace element just greater than nums[i] with nums[i]
                replace(ans, nums[i], i, indices, parent);
            }
        }
    }

    vector<int> lis;
    int lisIndex = indices.back();
    while (lisIndex != -1) {
        lis.push_back(nums[lisIndex]);
        lisIndex = parent[lisIndex];
    }

    reverse(lis.begin(), lis.end());
    return lis;
}