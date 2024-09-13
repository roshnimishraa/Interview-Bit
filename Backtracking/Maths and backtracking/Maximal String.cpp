Time Complexity: O(n^2B ) 
Space Complexity: O(B)

void helper(string A, int B, string &max){
    if(B==0){
        return;
    }
    for(int i=0;i<A.length();i++){
        for(int j=i+1;j<A.length();j++){
            swap(A[i],A[j]);
            if(A>max){
                max=A;
            }
            helper(A,B-1,max);
            swap(A[i],A[j]);
        }
    }
}
string Solution::solve(string A, int B) {
     string max=A;
    helper(A,B,max);
    return max;
}
