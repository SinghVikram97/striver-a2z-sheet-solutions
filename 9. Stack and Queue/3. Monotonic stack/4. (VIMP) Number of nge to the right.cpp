// https://www.geeksforgeeks.org/problems/number-of-nges-to-the-right/1

// Brute force
class Solution{
public:

    vector<int> count_NGE(int n, vector<int> &arr, int queries, vector<int> &indices){
        vector<int> nge(n,-1);
        
        for(int i=0;i<n;i++){
            int count=0;
            for(int j=i+1;j<n;j++){
                if(arr[j]>arr[i]){
                    count++;
                }
            }
            nge[i]=count;
        }
        
        vector<int> ans;
        
        for(int i=0;i<indices.size();i++){
            ans.push_back(nge[indices[i]]);
        }
        
        return ans;
       
    }

};

// Optimised using merge sort
// Similar question on leetcode: https://leetcode.com/problems/count-of-smaller-numbers-after-self/description/
// First solve number of inversions

// https://www.geeksforgeeks.org/inversion-count-in-array-using-merge-sort/
/*
In an array if x, y at index i,j

then if x>y and i<j then inversion

2, 9, 6
the pair of numbers (9, 6) is an inversion.
Check Arrays/Hard

*/


// Now using same concept we can solve this: https://leetcode.com/problems/count-of-smaller-numbers-after-self/solutions/445769/merge-sort-clear-simple-explanation-with-examples-o-n-lg-n/
/*
Here we just have to calculate no of inversions for each number

while merging

[9,11,15] and [2,5,10]

we can see 2<9 and 2 will be less than each element after 9 since sorted so we have to increment inversion for each element
instead of that we keep a count of elements that were smaller
so elementsSmaller = 2 (2 and 5)
and now 9 <10
so we add elementsSmaller as inversions for 9

now 11>10 so we increment elementsSmaller as 3
so we lazily update

also we need pair<int,int> as we need to return ans according to original index
*/
class Solution {
public:
    void merge(vector<pair<int,int> > &arr, vector<pair<int,int> > &left, vector<pair<int,int> > &right, vector<int> &finalAns){
        int i=0;
        int j=0;
        int k=0;
        
        int n1=left.size();
        int n2=right.size();
        
        int numElementsSmallerRight=0;
        
        while(i<n1 && j<n2){
            if(left[i].first<=right[j].first){
                finalAns[left[i].second]+=numElementsSmallerRight;
                arr[k].first=left[i].first;
                arr[k].second=left[i].second;
                i++;
                k++;
            }else{
                // it means left[i]>right[j]
                // and since it lies on left size so inversion
                // all remaining elements of left will also be greater than this right[j]
                // since left sorted remaining elements greater than left[i]
                numElementsSmallerRight++;
                arr[k].first=right[j].first;
                arr[k].second=right[j].second;
                j++;
                k++;
            }
        }
        
        while(i<n1){
            finalAns[left[i].second]+=numElementsSmallerRight; // IMP
            arr[k].first=left[i].first;
            arr[k].second=left[i].second;
            i++;
            k++;
        }
        
        while(j<n2){
            arr[k].first=right[j].first;
            arr[k].second=right[j].second;
            j++;
            k++;
        }
    }
    void mergeSort(vector<pair<int,int> > &arr, int start, int end, vector<int> &finalAns){
        if(start>=end){
            return;
        }

        int n=(end-start+1);

        int mid=(n-1)/2;

        vector<pair<int,int> > left;
        vector<pair<int,int> > right;

        for(int i=start;i<=mid;i++){
            left.push_back({arr[i].first, arr[i].second});
        }

        for(int i=mid+1;i<=end;i++){
            right.push_back({arr[i].first, arr[i].second});
        }

        // sort both arrays
        mergeSort(left, 0, left.size()-1, finalAns);
        mergeSort(right, 0, right.size()-1, finalAns);

        // merge both
        merge(arr, left, right, finalAns);
    }
    vector<int> countSmaller(vector<int>& nums) {
        int n=nums.size();
        vector<int> finalAns(n, 0);

        vector<pair<int,int> > arr;
        for(int i=0;i<n;i++){
            arr.push_back({nums[i],i});
        }

        mergeSort(arr, 0, n-1, finalAns);

        return finalAns;
    }
};