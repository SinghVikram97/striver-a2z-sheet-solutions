// https://leetcode.com/problems/lemonade-change/description/
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        // $10 = One 5$
        // $20 = One 10$ and One 5$ or three 5$
        int five=0;
        int ten=0;
        for(int i=0;i<bills.size();i++){
            if(bills[i]==5){
                five++;
            }else if(bills[i]==10){
                if(five==0){
                    return false;
                }
                five--;
                ten++;
            }else{
                if(ten>0 && five>0){
                    five--;
                    ten--;
                }else if(five>=3){
                    five=five-3;
                }
                else{
                    return false;
                }
            }
        }
        return true;
    }   
};