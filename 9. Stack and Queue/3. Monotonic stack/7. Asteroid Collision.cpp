// https://leetcode.com/problems/asteroid-collision/description/

// Process elements and keep them in a separate vector
// - means moving left, + means moving right

/*
- + won't collide
+ + won't collide
- - wont' collide
+ - will collide

use same logic as merge overlappping intervals
*/
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& v) {
        int n=v.size();

        stack<int> ans;

        for(int i=0;i<n;i++){
            if(ans.empty()){
                ans.push(v[i]);
                continue;
            }

            
            // try to push v[i]
            while(!ans.empty()){
                int prevElement = ans.top();

                if(prevElement>=0 && v[i]>=0){
                    ans.push(v[i]);
                    break; 
                }else if(prevElement<0 && v[i]<0){
                    ans.push(v[i]);
                    break;
                }else if(prevElement<0 && v[i]>=0){
                    ans.push(v[i]);
                    break;
                }else{
                    // collision
                    ans.pop();
                    if(abs(v[i])>abs(prevElement)){       
                        // If stack gets empty can push v[i]
                        if(ans.empty()){
                            ans.push(v[i]);
                            break;
                        }else{
                            // else find its position
                            continue;
                        }
                    }else if(abs(prevElement)>abs(v[i])){
                        // no change prevElement survives
                        ans.push(prevElement);
                        break;
                    }else{
                        // both destroyed
                        break;
                    }
                }
            }
        }

        int size=ans.size();

        vector<int> finalAns(size);

        int i=size-1;

        while(i>=0){
            finalAns[i]=ans.top();
            ans.pop();
            i--;
        }

        return finalAns;
    }
};