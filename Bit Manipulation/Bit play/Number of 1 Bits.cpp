int Solution::numSetBits(unsigned int A) {
    int ans =0;
    while(A>0){
        A = A & (A-1);
        ans++;
    }
    return ans;
}
