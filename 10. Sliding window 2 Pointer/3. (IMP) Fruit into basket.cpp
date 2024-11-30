// https://www.geeksforgeeks.org/problems/fruit-into-baskets-1663137462/1

/*
Max window length with 2 fruit types
*/

// remove a fruit from the window
// which fruit to remove
// can;t check for set size since we may have added same fruit type multiple times
// 2 2 2 2 2 1 1 3
// at 3 we have to remove 2
// but it can also be like
// 2 1 2 1 2 1 2 3

// So we can't keep a set
// Instead we can keep the last position of both the fruits
// We have to move to last position + 1 of the fruit which is more to the left

// IMP: setting map key as 0 doesn't remove it from the map, size is not affected
// You have to erase it from the map

class Solution {
  public:
    int totalFruits(vector<int> &arr) {
        int n=arr.size();
        
        int left=0;
        int right=0;
        
        // fruitType, lastSeenPosition
        unordered_map<int,int> fruitType;
        
        int ans=0;
        while(left<=right && right<n){
            if(fruitType.find(arr[right])==fruitType.end()){
                
                // New fruit
                if(fruitType.size()==2){
                    // remove a fruit from basket
                    
                    // remove a fruit from the window
                    // which fruit to remove
                    // can;t check for set size since we may have added same fruit type multiple times
                    // 2 2 2 2 2 1 1 3
                    // at 3 we have to remove 2
                    
                    // but it can also be like
                    // 2 1 2 1 2 1 2 3
                    
                    // move left to leftMost last seen for 2 fruits
                    
                    auto it1=fruitType.begin();
                    
                    auto it2=fruitType.begin();
                    it2++;
                    
                    
                    if(it1->second<it2->second){
                        left=it1->second+1;
                        fruitType.erase(it1->first);
                    }else{
                        left=it2->second+1;
                        fruitType.erase(it2->first);
                    }
                    
                    // add new fruit
                    fruitType[arr[right]]=right;
                    // update ans
                    ans=max(ans, right-left+1);
                    // extend window
                    right++;

       
                }else{
                    // Fine
                    // update last seen index
                    fruitType[arr[right]]=right;
                    // update ans
                    ans=max(ans, right-left+1);
                    // extend window
                    right++;
                }
            }else{
                // existing fruitType so won't increase number of distinct fruits
    
                // update last seen index
                fruitType[arr[right]]=right;
                // update ans
                ans=max(ans, right-left+1);
                // extend window
                right++;
            }
        }
        
        return ans;
    }
};