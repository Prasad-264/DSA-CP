#include<bits/stdc++.h>
using namespace std;
int N = 1000000;
bool isPrime[N+5];

bool sieveOfEratothenes() {
    for(int i=2; i<N; i++) {
        isPrime[i] = true;
    }

    for(int i=2; i*i<=N; i++) {
        if(isPrime[i] == true) {
            for(int j = i*i; j<=N; j+=i) {
                isPrime[i] = false;
            }
        }
    }
}
int main() {
    
    return 0;
}