// https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/description/

// Brute Force - O(n^2)
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int maxi=0;
        int n=nums.size();

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                maxi=max(maxi, nums[i]^nums[j]);
            }
        }

        return maxi;
    }
};

/*
Trie intution 

First understand the problem given an array and a number x we have to find maximum xor b/w any number from array and x
We first insert array numbers into a trie as bits

Now for maximum xor let's suppose x in bits is 10011010 
We want our number to have maximum bits set from left since left has more power
So we want other number to have different bit at a given position

So number should have 0 first now we see in trie if 0 is there we take 1 in ans and go down 0
now next we should have 1 , if 1 not there we have no option we take 0 and in our ans we take that bit as 0 

So we implement a function in Trie
getMax(int x)

which returns maximum xor b/w any number in our array and x

Now this can be used if we have 2 arrays and we have to find max xor b/w elements of 2 arrays 
we construct trie using one array and then consider x as every element of other array

In this problem we have single array so we build trie using that array and then consider x as every element of that array
*/


/*
How to get ith bit of a number
for example 25 is
1 1 0 0 1
4 3 2 1 0

5th bit , right shift number by i-1 ie 4 bits to get the 5th bit

We can flip a bit by doing 1-bit 
*/
class TrieNode{
    vector<TrieNode*> bits{2, NULL}; // 0 and 1
    // don't need flag since we always traverse all 32 bits

public:
    TrieNode(){
        
    }

    bool containsKey(int bit){
        if(bits[bit]!=NULL){
            return true;
        }else{
            return false;
        }
    }

    TrieNode* addKey(int bit){
        TrieNode *newNode = new TrieNode();
        this->bits[bit]=newNode;
        return newNode;
    }
    
    TrieNode* getKey(int bit){
        return bits[bit];
    }
};
class Trie {
public:
    TrieNode *root;

    Trie() {
        root=new TrieNode();
    }
    
    void insert(int num) {
        TrieNode *curNode = root;

        // traverse all 32 bits
        for(int i=31;i>=0;i--){
            // i 31 means right shift 31 times to get the 32nd bit
            int bit = (num>>i) & 1; 

            if(curNode->containsKey(bit)){
                curNode = curNode->getKey(bit);
            }else{
                curNode = curNode->addKey(bit);
            }
        }
    }

    int getMax(int x){
        int ans = 0; // intially all 32 bits as 0
        TrieNode *curNode = root;

        // traverse all 32 bits
        for(int i=31;i>=0;i--){
            int xBit = (x>>i) & 1;

            int flippedBit = 1-xBit;

            // We want opposite/flipped bit
            if(curNode->containsKey(flippedBit)){
                // if it does we set this bit as 1 in our ans
                ans = ans | (1<<i); // take OR with bit set at ith bit
                curNode = curNode -> getKey(flippedBit);
            }else{
                // else take original bit ie. other option
                ans = ans | (0 << i); // can skip this since we have set all bits as 0 initially
                curNode = curNode -> getKey(xBit);
            }
        }

        return ans;
    }
    
    
};
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie *trie = new Trie();

        for(int i=0;i<nums.size();i++){
            trie->insert(nums[i]);
        }

        int maxi=-1;

        for(int i=0;i<nums.size();i++){
            maxi=max(maxi, trie->getMax(nums[i]));
        }

        return maxi;
    }
};