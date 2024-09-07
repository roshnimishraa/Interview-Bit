Brute Force Approach 
min of maximum 
ans += min(maxofLeft, maxofRight) - A[i] 

TC : O(N^2) 
SC : O(1) 

int Solution::trap(const vector<int> &A) {
          int ans=0;
        int n = A.size();
    for(int i=0; i<n; i++)
    {
        int j=i;
        int leftMax=0, rightMax=0;
    while(j >= 0){
        leftMax = max(leftMax, A[j]);
        j--; //i to 0
    }
    j = i;
    while( j< n)
    {
        rightMax = max(rightMax, A[j]);
        j++;
    }
    ans += min(leftMax, rightMax) - A[i];
    }
    return ans;
}

-------------------------------------------------------------------------------------------------------------------------------------------------------------

Approach 2 : Better 

Intuition: We are taking O(N) for computing leftMax and rightMax at each index. The complexity can be boiled down to O(1) if we precompute 
the leftMax and rightMax at each index.

Time Complexity: O(3*N) as we are traversing through the array only once. And O(2*N) for computing prefix and suffix array.

Space Complexity: O(N)+O(N) for prefix and suffix arrays.

vector<int> prefix(const vector<int> &A) {
    int n = A.size();
    vector<int> pre(n);
    pre[0] = A[0]; 
   
    for (int i = 1; i < n; i++) {
        pre[i] = max(pre[i - 1], A[i]);
    }
    
    return pre;
}

vector<int> suffix(const vector<int> &A) {
    int n = A.size();
    vector<int> suff(n);
    suff[n - 1] = A[n - 1];  
    
  
    for (int i = n - 2; i >= 0; i--) {
        suff[i] = max(suff[i + 1], A[i]);
    }
    
    return suff;
}

int Solution::trap(const vector<int> &A) {
    int n = A.size();
    if (n == 0) return 0;  
    
    vector<int> pre = prefix(A);
    vector<int> suff = suffix(A);

    int ans = 0;
    
    for (int i = 0; i < n; i++) {
        ans += min(pre[i], suff[i]) - A[i];
    }

    return ans;
}

          
