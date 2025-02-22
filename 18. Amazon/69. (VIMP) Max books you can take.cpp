// https://leetcode.com/problems/maximum-number-of-books-you-can-take/description/

// TLE
// Consider each book as the last book we have taken
/*
Let ai be number of books we take from ith shelf
We have to 2 constrains on ai

1. ai <=books[i]  can take more than available books 
2. ai <= ai+1 -1  strictly fewer than books from shelf i+1
*/
class Solution {
public:
    long long maximumBooks(vector<int>& books) {
        int n=books.size();

        long long int maxi=-1;

        for(int i=0;i<n;i++){
            // consider each book as last book
            long long int count=books[i];
            long long int booksAllowed=books[i]-1;

            for(int j=i-1;j>=0;j--){
                if(booksAllowed<=0){
                    break;
                }
                // min of allowed, available
                int booksToTake=min<long long int>(booksAllowed, books[j]);
                count=count+booksToTake;
                // set new books allowed
                booksAllowed=booksToTake-1;
            }
            maxi=max(count, maxi);
        }
        return maxi;
    }
};

// Using DP
/*
dp[i] = max books that can be taken with books[i] as last shelf

Lets say no barrier to selecting ie. we start from i, take books[i] then books[i]-1 from i-1 and so on

How many shelfs can we go through
it would be max(books[i], i+1) as books[i] can also become 0

13 12 10 6 7
0  1  2 3 4

here if take books[i] = 7 we can take 4+1 = 5 books

but if it was 3 then it would have turned 0 earlier

so len = max(books[i], i+1)

now arithmetic progression sum of n terms is n/2 * [2a + (n-1) d]
d=1 here
a=books[i]
n=len


Now if this isn't the case, ie. there is some point where we don't get the intented number of books
we use dp[j] where j is that point

at position j we need books[i]-(i-j) books

if we have those many number of books we can pop from stack
*/
class Solution {
public:
    long long maximumBooks(vector<int>& books) {
        int n=books.size();
        vector<long long int> dp(n, 0);

        stack<int> ms; // stores indexes

        long long int ans=0;

        for(int i=0;i<n;i++){
            // check choke point where we can't follow arithmetic progression

            // we can remove elements which have more books than desired 
            while(!ms.empty() && books[ms.top()] >= books[i] - (i - ms.top())){
                ms.pop();
            }

            if(ms.empty()){
                int len=min(books[i],i+1);
                dp[i]=(long long)len * (2LL * books[i] - len + 1) / 2LL;
            }else{
                int j = ms.top();
                int len = i - j;  // The length of the new segment (shelves j+1..i).
                // The sum for this new segment (using arithmetic series formula)
                // is: len * (2 * books[i] - len + 1) / 2,
                // and we add dp[j] which is the sum of the segment ending at j.
                dp[i] = dp[j] + (long long)len * (2LL * books[i] - len + 1) / 2LL;
            }
            // Push the current index i onto the stack as a candidate boundary for future indices.
            ms.push(i);
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};

/*
Questions
Could there be a choke point j < i, such that, it is a choke point for books[i+1], but not for books[i].

So we remove from stack since
books[j] >= books[i]-(i-j)

books[j]+i-j > = books[i]

Now to become choke point for books[i]
books[j] < books[i+1] - (i+1-j)


books[i+1] > books[j]+i-1-j

books[i+1] > (books[j]+i-j)-1

books[i+1] > books[i]-1

books[i] < books[i+1]+1 so i would become a choke point for i+1 not j
https://leetcode.com/problems/maximum-number-of-books-you-can-take/solutions/2358714/java-stack-dp-find-that-bottleneck-explanations-proof-comments-while-i-was-coding/

*/