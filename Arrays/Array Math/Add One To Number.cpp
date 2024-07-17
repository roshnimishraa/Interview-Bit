vector<int> Solution::plusOne(vector<int> &A) {
    vector<int> ans;
    int carry=1;
    int n = A.size();
    int msb = n-1;
    for(int i=n-1;i>=0;i--){
      int sum = carry + A[i];
      carry = sum/10;
      A[i] = sum%10;
    //   if sum has some value
    if(sum){
        msb = i; 
    }
    }
    
    // update ans array
    for(int i=n-1;i>=msb;i--)
        ans.push_back(A[i]);
       if(carry)
        ans.push_back(carry); 
        reverse(ans.begin(),ans.end());
    
    return ans;
}
