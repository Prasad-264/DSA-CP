/*
Given an even number N (greater than 2), return two prime numbers whose sum will 
be equal to given number. There are several combinations possible. Print only the 
pair whose minimum value is the smallest among all the minimum values of pairs and print the minimum element first.

NOTE: A solution will always exist, read Goldbachs conjecture. 

Example 1:

Input: N = 74
Output: 3 71
Explaination: There are several possibilities 
like 37 37. But the minimum value of this pair 
is 3 which is smallest among all possible 
minimum values of all the pairs.


Example 2:

Input: 4
Output: 2 2
Explaination: This is the only possible 
prtitioning of 4.
*/

int N = 10000;
vector<int> isPrime(N+5, 1);

class Solution {
private:
    void sieveOfEratosthenes() {
        for(int i=2; i*i<N; i++) {
            if(isPrime[i]) {
                for(int j = i*i; j<N; j+=i) {
                    isPrime[j] = 0;
                }
            }
        }
    }
public:
    vector<int> primeDivision(int n) {
        sieveOfEratosthenes();
        for(int i=2; i<=(n/2)+1; i++) {
            if(isPrime[i] && isPrime[n-i]) {
                return {i, n-i};
            }
        }
    }
};