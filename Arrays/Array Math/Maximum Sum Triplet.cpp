int Solution::solve(vector<int> &A)
{
    int n = A.size();
    int ans=0;
    // right suffix array
    vector<int> right(n);
    for(int i=n-1;i>=0;i--){
        if(i == n-1){
            right[i] = A[i];
        }
        else{
            right[i] = max(right[i+1],A[i]);
        }
    }
    set<int> st;
    st.insert(A[0]);
    for(int i=1;i<n;i++){
        st.insert(A[i]);
        
          // Find ele less than i 
          auto it = st.find(A[i]); //find own element 
        //   if min. element of i doesn't exist && if i is at last index then it's right doesn't exist
        if(it!=st.begin() && right[i]!=A[i])
    
         ans = max (ans, (*--it) + A[i] + right[i]);
         
    }
    return ans;
}
