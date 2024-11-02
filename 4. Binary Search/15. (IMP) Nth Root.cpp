// https://www.geeksforgeeks.org/problems/find-nth-root-of-m5843/1
class Solution{
	public:
	int NthRoot(int n, int m)
	{
        long long int start=1;
        long long end=m;
        
        while(start<=end){
            long long mid=(start+end)/2;
            
            long long nrt=1;
            
            // Overflow
            for(int i=0;i<n;i++){
                nrt=nrt*mid;
                if(nrt>m){
                    break; //stop early
                }
            }

            if(nrt==m){
                return mid;
            }else if(nrt>m){
                // move left
                end=mid-1;
            }else{
                // move right
                start=mid+1;
            }
        }
        
        return -1;
	}  
};