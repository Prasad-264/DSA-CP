int Solution::maxSubArray(const vector<int> &A) {
    int n = A.size();
    int sum = 0;
    int maxi = INT_MIN; 
    for(int i=0; i<n; i++) {
        sum += A[i];
        maxi = max(sum, maxi); 
        if(sum < 0) sum = 0;
    }
    return maxi;
}