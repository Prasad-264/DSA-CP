/*
bit representation of 7  -> 0111
bit representation of 8  -> 1000
bitwise AND of 7 and 8 -> 0000
we are gonna use this property for for all numbers which are powers of two
*/

class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n > 0 && ((n & (n-1)) == 0);
        
    }
};

/*
    bool isPowerOfTwo(int n) {
        if (n <= 0) return false;
        while (n%2 == 0) n/=2;
            return n == 1;
            
        }
*/

/*
    bool isPowerOfTwo(int n) {
        return n > 0 && (1073741824 % n == 0);     // 2^30 = 1073741824
        
    }
*/