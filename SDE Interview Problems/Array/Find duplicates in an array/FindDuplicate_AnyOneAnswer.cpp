int Solution::repeatedNumber(const vector<int> &A) {
    int n = A.size();
    int hash[n] = {0};
    for(int i=0; i<n; i++) {
        hash[A[i]]++;
    }
    for(int j=0; j<n; j++) {
        if(hash[j]>1) return j;
    }
    return -1;
}