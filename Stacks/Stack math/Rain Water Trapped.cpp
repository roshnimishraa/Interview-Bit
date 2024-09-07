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
