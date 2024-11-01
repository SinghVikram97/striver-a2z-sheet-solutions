// https://leetcode.com/problems/search-in-rotated-sorted-array-ii/description/

// Previous had distinct values but this one doesn't
// Still same code will work because we have handled the case 
// of arr[mid]==arr[start] or arr[mid]==arr[end]

class Solution {
public:
    bool search(vector<int>& arr, int target) {
        int start=0;
        int end=arr.size()-1;

        while(start<=end){
            int mid=(start+end)/2;

            if(arr[mid]==target){
                return true;
            }
            else if(arr[end]>arr[start]){
                // array is sorted
                if(arr[mid]>target){
                    end=mid-1;
                }else{
                    start=mid+1;
                }
            }else if(arr[mid]<arr[start]){
                    // left unsorted
                    // check in right
                    if(target>arr[mid] && target<=arr[end]){
                        start=mid+1;
                    }else{
                        end=mid-1;
                    }
            }else if(arr[mid]>arr[end]){
                    // right unsorted
                    // left sorted
                    if(target<arr[mid] && target>=arr[start]){
                        end=mid-1;
                    }else{
                        start=mid+1;
                    }
            }
            else{
                    // arr[mid] == arr[start] and not target
                    if(arr[mid]==arr[start]){
                        start++;
                    }
                    if(arr[mid]==arr[end]){
                        end--;
                    }
            }
        }
        return false;
    }
};