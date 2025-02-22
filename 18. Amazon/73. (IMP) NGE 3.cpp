// https://leetcode.com/problems/next-greater-element-iii/description/

// Same as next permutation question
class Solution {
public:
    int nextGreaterElement(int n) {
        
        // Convert to string
        string num=to_string(n);

        if(num.length()<=1){
          return -1;
        }

        // Start from last and find a num such that it is less than it's right element
        // ie. arr[i-1]<arr[i]

        int size=num.length();
        int firstIndex=-1;
        for(int i=size-1;i>0;i--){
          if(num[i-1]<num[i]){
            firstIndex=i-1;
            break;
          }
        }

        if(firstIndex==-1){
          // No's arranged in decreasing order ex. 98765
          // Not possible
          return -1;
        }

        // Now find smallest number greater than this number ie. num[firstIndex]
        // From firstIndex+1
        int secondIndex=-1;
        for(int i=firstIndex+1;i<size;i++){
          if(num[i]>num[firstIndex]){
            if(secondIndex==-1){
              secondIndex=i;
            }
            else{
              if(num[i]<num[secondIndex]){
                secondIndex=i;
              }
            }
          }
        }

        // Swap both numbers 
        swap(num[firstIndex],num[secondIndex]);

        // reverse the numbers from firstIndex+1 to end to arrange them in increasing order
        // Currently they are in decreasing order 
        sort(num.begin()+firstIndex+1,num.end());

        // Convert back to integer and return 
        
        long int ans=stol(num);
        
        if(ans>=INT_MAX){
            return -1;
        }
        return (int)ans;
        


    }
};