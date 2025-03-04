// https://leetcode.com/problems/online-stock-span/description/

// Brute Force
class StockSpanner {
public:
    vector<int> prices;
    StockSpanner() {
    }
    
    int next(int price) {
        prices.push_back(price);

        int n = prices.size();

        int i=n-2;

        int count=1;
        while(i>=0){
            if(prices[i]<=price){
                i--;
                count++;
            }else{
                break;
            }
        }

        return count;
    }
};

// Optimal approach
/*
arr = [7, 34, 1, 2, 5, 8]

Since we want decreasing numbers we maintain a decreasing stack ie. element at the bottom largest
We also push num of numbers <= that element in the stack

push (7,1)

34
34>7

Now if an element reaches 34 and is greater > 34 then for it ans would be +2 
otherwise it would stop at 34 ie. 34 and 7 both don't matter

So we take out 7 and push (34,2) ie. if number greater than 34 then number of elements <=34 are 2

stack = {34,2}

1
1<34
push {1,1}

stack = {34,2}{1,1}

2
2>1

so 1+(elements<=1)=2

2<34 so won't go beyond 34
push {2,2} onto stack

stack= {34,2}{2,2}

number of elements <= 2 are 2

Now comes 5

NOTE CONSECUTIVE DAYS
Example: 34, 7, 1, 2, 1
here for last 1 ans is 1
*/
class StockSpanner {
public:
    stack<pair<int,int> > ms; // element, number of elements <= element
    StockSpanner() {
        
    }
    
    int next(int price) {
        int count=0;
        // collect all elements <= current price 
        while(!ms.empty() && price>=ms.top().first){
            count=count+ms.top().second;
            ms.pop();
        }

        ms.push({price, count+1});

        return count+1;
    }
};