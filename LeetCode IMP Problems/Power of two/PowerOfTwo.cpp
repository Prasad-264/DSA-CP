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