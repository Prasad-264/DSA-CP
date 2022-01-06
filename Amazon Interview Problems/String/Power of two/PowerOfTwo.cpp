int Solution::power(string A) {
    int N = A.length();

    //Method 1
    int num = A[0]-'0';
    for(int i = 1; i<N; i++){ 
        num = (num*10) + (A[i]-'0');
        //cout << num << endl;
    }
    if(num == 1) return 0;
    //cout << num << endl;
    int power = log(num)/log(2);
    
    if(pow(2,power) == num) return 1;
    else return 0;
    
    //Method 2
    //for eg: 8 - 1000 and 7 - 0111. So 1000&0111 = 0. 
    //if((num & (num-1)) == 0) return 1;
    return 0;
};