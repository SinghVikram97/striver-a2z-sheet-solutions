// https://www.geeksforgeeks.org/problems/merge-k-sorted-arrays/1

// [0,1,2,3,4,5]
// left=0, right=5
/*  
    Merge 2 sorted lists left and right and put in left
    [(0,5),(1,4),(2,3)]

    Repeat 
    [(0,5,2,3)(1,4)]

    Repeat
    [(0,5,2,3,1,4)]

    repeat till you have only one list
*/
// Time complexity 
/*
1st pass: k/2 merges, N size -> O(kn)
2nd pass: k/4 merges, 2n size -> O(kn)


logk passes

So TC: O(knlogk)
*/
class Solution
{
    public:
    //Function to merge k sorted arrays.
    vector<int> mergeSortedList(vector<int> &a, vector<int> &b){
        int n1=a.size();
        int n2=b.size();
        
        int i=0;
        int j=0;
        
        vector<int> ans;
        
        while(i<n1 && j<n2){
            if(a[i]<=b[j]){
                ans.push_back(a[i]);
                i++;
            }else{
                ans.push_back(b[j]);
                j++;
            }
        }
        
        while(i<n1){
            ans.push_back(a[i]);
            i++;
        }
        
        while(j<n2){
            ans.push_back(b[j]);
            j++;
        }
        
        return ans;
    }
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        int last=K-1;
        
        while(last!=0){
            int left=0, right=last;
            while(left<right){
                vector<int> ans=mergeSortedList(arr[left],arr[right]);
                arr[left]=ans;
                left++;
                right--;
            }
            last=right;
        }
        return arr[0];
    }
};


// Using heap
// TC - We process total n*k elements and for each insertion and removal it takes logk time since at a time k elements in heap
// TC - O(n*k*logk)
class Solution
{
    public:
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int k)
    {
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>> > pq;
        
        // push element, array number, index
        for(int i=0;i<k;i++){
            pq.push({arr[i][0], {i, 0}});
        }
        
        vector<int> ans;
        
        while(!pq.empty()){
            pair<int,pair<int,int>> pp=pq.top();
            pq.pop();
            
            ans.push_back(pp.first);
            
            int arrNumber = pp.second.first;
            int index = pp.second.second+1; // push next number
            
            if(index<arr[arrNumber].size()){
                pq.push({arr[arrNumber][index],{arrNumber, index}});
            }
        }
        
        return ans;
    }
};