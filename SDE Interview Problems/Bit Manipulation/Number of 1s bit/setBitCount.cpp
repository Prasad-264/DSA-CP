/*
Given a positive integer N, print count of set bits in it. 

Example 1:

Input:
N = 6
Output:
2
Explanation:
Binary representation is '110' 
So the count of the set bit is 2.


Example 2:

Input:
8
Output:
1
Explanation:
Binary representation is '1000' 
So the count of the set bit is 1.

*/

//---------------------------------- Using STL ----------------------------------------------

class Solution {
  public:
    int setBits(int n) {
        int count = __builtin_popcount(n);
        return count;
    }
};


//----------------------------------- Another Approch --------------------------------------

class Solution {
  public:
    int setBits(int n) {
        int count = 0;
        while(n != 0) {
            if(n & 1 == 1) count++;
            n >>= 1;
        }
        return count;
    }
};

//------------------------------------- Another Approch -----------------------------------------

class Solution {
  public:
    int setBits(int n) {
        int count = 0;
        while(n != 0) {
            n &= n-1;
            count++;
        }
        return count;
    }
};