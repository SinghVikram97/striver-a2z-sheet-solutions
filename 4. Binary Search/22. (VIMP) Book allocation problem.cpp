// /https://www.naukri.com/code360/problems/allocate-books_1090540

// we have to minimize the max number of pages assigned to a student
// so search space is possible values for max pages

// minimum would be smallest element in array 
// maximum would be all elements in array ie. all books

// let's say we choose maxPages
// now 3 cases
// using this maxPages we are able to allocate books to m students -> decrease maxPages and store in ans
// using this maxPages we are able to allocate books to > m students -> increase maxPages, don't store in ans
// using this maxPages we are able to allocate books to < m students -> decrease maxPages , and store in ans

/*
so if able to allocate books to <=m students store in ans 

why < m students also work because this is maxPages, we can always give less pages to some students and have m as our answer
for example
1 2 3 4 7
and students = 4
and maxPages = 7

we will get students = 3 but we can give less pages and get (1), (2,3), (4), (7)

*/

bool help(int maxPages, vector<int> &arr, int numStudents){
    // we have to allocate books to students such that max number of pages per student shouldn't go above maxPages
    // below that is fine

    int n=arr.size();

    int count=-1;
    int countPages=0;
    for(int i=0;i<n;i++){
        // a single book is greater than maxNumber of pages we can allocate to a student so not possible
        if(arr[i]>maxPages){
            return false;
        }
        if(countPages+arr[i]<=maxPages){
            // can assign this book to current student
            countPages+=arr[i];
            if(count==-1){
                // first student
                count=1;
            }
        }else{
            // have to assign this to next student
            countPages=arr[i];
            count++;

            if(count>numStudents){
                return false;
            }
        }
    }

    return true;
}
int findPages(vector<int>& arr, int n, int m) {
    // if number of students > number of books not possible
    if(m>n){
        return -1;
    }
    int mini=INT_MAX;
    int sum=0;

    for(int i=0;i<n;i++){
        mini=min(arr[i],mini);
        sum+=arr[i];
    }

    int start=mini;
    int end=sum;

    int ans=-1;
    while(start<=end){
        int mid=(start+end)/2;

        bool possible=help(mid, arr, m);

        if(possible){
            // try to minimize it 
            // ie. decrease max pages
            ans=mid;
            end=mid-1;
        }else{
            // increase max pages
            start=mid+1;
        }
    }
    return ans;
}