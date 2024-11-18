// https://leetcode.com/problems/median-of-two-sorted-arrays/

// Naive -> merge 2 sorted arrays in O(N)
// Median -> middle element

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> v;

        int n1=nums1.size();
        int n2=nums2.size();
        
        int i=0;
        int j=0;

        while(i<n1 && j<n2){
            if(nums1[i]<=nums2[j]){
                v.push_back(nums1[i]);
                i++;
            }else{
                v.push_back(nums2[j]);
                j++;
            }
        }

        while(i<n1){
            v.push_back(nums1[i]);
            i++;
        }
        while(j<n2){
            v.push_back(nums2[j]);
            j++;
        }

        if(v.size()%2!=0){
            return (double)v[v.size()/2];
        }else{
            return ((double)v[v.size()/2]+v[v.size()/2-1])/2;
        }
    }
};

// Without extra space
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size();
        int n2=nums2.size();
        
        int i=0;
        int j=0;

        int size=n1+n2;

        int count=-1; // index starts from 0
        int ele1;
        int ele2;

        while(i<n1 && j<n2){
            if(nums1[i]<=nums2[j]){
                count++;
                if(count==size/2){
                    ele1=nums1[i];
                }else if(count==((size/2)-1)){
                    ele2=nums1[i];
                }
                i++;
                
            }else{
                count++;
                if(count==size/2){
                    ele1=nums2[j];
                }else if(count==((size/2)-1)){
                    ele2=nums2[j];
                }
                j++;
            }
        }

        while(i<n1){
            count++;
            if(count==size/2){
                ele1=nums1[i];
            }else if(count==((size/2)-1)){
                ele2=nums1[i];
            }
            i++;
        }
        while(j<n2){
            count++;
            if(count==size/2){
                ele1=nums2[j];
            }else if(count==((size/2)-1)){
                ele2=nums2[j];
            }
            j++;
        }
        cout<<ele1<<" "<<ele2<<endl;
        if(size%2!=0){
            return ele1;
        }else{
            return (ele1+ele2)/2.0;
        }
    }
};

// BASED on Question 32

// Number of elements before median = Number of elements after median
// but we can't only check number of elements less than median
/*
For example
1 2 2 2 3
Here median = 2 
number of elements less than 2 = 1

n=5
n/2=2

so we have to check number of elements <= median
and it should surely be greater than n/2 (> and not >= since we are including median as well)
*/

// Since both arrays sorted we can find number of elements <= to given element in logn time by finding upper bound

// Can;t use the above ie. same concept as question 32 here since here array can be even
// and for test case [1,2,3,7]
// num elements <=2.5 is 2 which is not greater than n/2 ie. 2

// !!!!!!!!! Works for odd elements the below solution !!!!!

class Solution {
public:
    int upperBound(double target, vector<int> &v){
        int size=v.size();
        if(size==0){
            return 0;
        }

        int start=0;
        int end=size-1;

        int ans=-1;
        while(start<=end){
            int mid=(start+end)/2;
            
            if(v[mid]<=target){
                ans=mid;
                // move further right
                start=mid+1;
            }else{
                // move left
                end=mid-1;
            }
        }
        return ans;
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size();
        int n2=nums2.size();

        int size=n1+n2;

        int target=size/2;

        // median b/w smallest element and largest element
        double mini1=n1 ? nums1[0] : INT_MAX;
        double mini2=n2 ? nums2[0] : INT_MAX;
        double start=min(mini1, mini2);

        double maxi1=n1 ? nums1[n1-1] : INT_MIN;
        double maxi2=n2 ? nums2[n2-1] : INT_MIN;
        double end=max(maxi1, maxi2);

        double ans=-1;
        while(start<=end){
            double mid=(start+end)/2.0;
            int upper1=upperBound(mid, nums1)+1; // index -> 3, elements -> 4
            int upper2=upperBound(mid, nums2)+1;
            cout<<mid<<" "<<upper1<<" "<<upper2<<endl;
            int numElementsLessEqualToMid=upper1+upper2;

            
            if(numElementsLessEqualToMid>target){
                // decrease end 
                // we want to find first element or leftmost element for which numElements <= to it > size/2
                ans=mid;
                end=mid-1;
            }else{
                start=mid+1;
            }
            
           
        }
        return ans;
    }
};


// SOLUTION
// We want to find elements at index size/2 and (size/2)-1 in the sorted array using binary search
// Try to solve the next question first -> kth element in 2 sorted arrays

// Using approach1 from previous question
class Solution {
public:
    int upperBound(int target, vector<int> &v){
        int size=v.size();
        if(size==0){
            return -1;
        }

        int start=0;
        int end=size-1;

        int ans=-1;
        while(start<=end){
            int mid=(start+end)/2;
            
            if(v[mid]<=target){
                ans=mid;
                // move further right
                start=mid+1;
            }else{
                // move left
                end=mid-1;
            }
        }
        return ans;
    }
    int kthElement(int k, vector<int>& arr1, vector<int>& arr2) {
        int n1=arr1.size();
        int n2=arr2.size();
        
        // kth element will lie b/w minimum and maximum number
        int mini1=n1 ? arr1[0] : INT_MAX;
        int mini2=n2 ? arr2[0] : INT_MAX;
        
        int maxi1=n1 ? arr1[n1-1] : INT_MIN;
        int maxi2=n2 ? arr2[n2-1] : INT_MIN;
        
        int start=min(mini1, mini2);
        int end=max(maxi1,maxi2);
        
        int ans=-1;
        while(start<=end){
            int mid=(start+end)/2;
            
            int up1=upperBound(mid, arr1) + 1; // index->3 elements->4
            int up2=upperBound(mid, arr2) + 1;

            if(up1+up2>=k){
                ans=mid;
                end=mid-1; // leftmost
            }else{
                start=mid+1;
            }
        }
        return ans;
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size();
        int n2=nums2.size();
        
        int i=0;
        int j=0;

        int size=n1+n2;
        
        if(size%2==0){
            int a = kthElement((size/2), nums1, nums2);
            int b = kthElement((size/2)+1, nums1, nums2);
            return (a+b)/2.0;
        }else{
            return kthElement((size/2)+1, nums1, nums2);
        }
    }
};