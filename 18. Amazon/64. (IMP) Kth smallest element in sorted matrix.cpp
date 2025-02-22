// https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/description/

// Use min heap
/*
Put smallest element into the min heap
Now put right and down elements to the min heap
And so on for k-1 times

After that we would have removed k-1 smallest elements in the matrxi
and top of min heap would be our ans

keep a visited array to ensure that you don't push same element again
someone's down might be someone's right
for example (1,0) right is (1,1)
and (0,1) down is (1,1)

Now to avoid visited array what we can do is push right only if it is from first row
Otherwise just down would work
*/
// TC: O(k log n)
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int m=matrix.size();
        int n=matrix[0].size();

        // push (i,j,val)
        // and sorted by val
        auto comp = [](auto &a, auto &b){
            return a.first>b.first; // imp for min heap
        };
        
        priority_queue<pair<int, pair<int,int> > , vector<pair<int, pair<int,int> > >, decltype(comp)> pq;
        
        // push 0,0
        pq.push({matrix[0][0], {0,0}});

        for(int i=0;i<k-1;i++){
            pair<int, pair<int,int> > ele=pq.top();
            pq.pop();

            int row=ele.second.first;
            int col=ele.second.second;

            if(row+1<m){
                pq.push({matrix[row+1][col], {row+1,col}});
            }

            if(row==0 && col+1<n){
                pq.push({matrix[row][col+1], {row, col+1}});
            }
        }

        return pq.top().first;
    }
};

// Using binary search approach where we find kth element in sorted array
// Which will be the first element for which num elements <= it would be atleast k

// So start = [0][0]
// End = [m-1][n-1]
// Mid
// Check upper bound ie. number of elements <= mid

// How to do that
/*
We know that matrix sorted row wise and column wise
We start at bottom left
We know upwards smaller and rightwards greater
*/
class Solution {
public:
    int calcUpperBound(vector<vector<int> > &mat, int mid){
        int m=mat.size();
        int n=mat[0].size();

        int count=0;
        int row=m-1;
        int col=0;

        while(row>=0 && col<n){
            if(mat[row][col]<mid){
                // since last element of col<mid
                // so whole col<mid (but from row=0 to current row ie. row+1 elements)
                count=count+row+1;
                // move to next col
                col++;
            }else if(mat[row][col]>mid){
                // since greater so move upwards to reduce element we want <=
                row--;
            }else{
                // equal so while col<=mid
                count=count+row+1;
                // move to next col
                col++;
            }
        }
        return count;
    }
    int kthSmallest(vector<vector<int>>& mat, int k) {
        int m=mat.size();
        int n=mat[0].size();

        int start=mat[0][0];
        int end=mat[m-1][n-1];

        int ans;
        while(start<=end){
            int mid=(start+end)/2;

            int elementsLessThanEqual = calcUpperBound(mat, mid);

            if(elementsLessThanEqual>=k){
                ans=mid;
                // move left
                end=mid-1;
            }else{
                start=mid+1;
            }
        }

        return ans;

    }
};