// Printing Catalan Number
#include<bits/stdc++.h>
using namespace std;

int catalan(int n) {
    if(n <= 1) {
        return 1;
    }
    int res = 0;
    for(int i=0; i<=n-1; i++) {
        res += catalan(i) * catalan(n-i-1);
    }
    return res;
}

int main() {
    for(int i=0; i<=10; i++) {
        cout << catalan(i) << " ";
    }
    cout << endl;
    return 0;
}

/*
APPLICATION OF CATALAN NUMBERS
-------------------------------
1.Possible BSTs
2.Paranthesis / brackets combinations
3.Possible forests
4.Ways of triangulations
5.Possible paths in martix
6.Dividing a circle using N chorrds
7.Dyck words of given length & much more

*/