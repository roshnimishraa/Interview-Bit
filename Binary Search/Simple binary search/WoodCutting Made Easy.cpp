TYPE -> BS ON ANSWERS 

int check(vector<int> &A, int B, int mid)
{
    int n = A.size();
    long long sum = 0;
    for(int i=0;i<n;i++){
        if(A[i] > mid){
            sum += (A[i] - mid);
        }
    }
    return sum >= B;
}

int Solution::solve(vector<int> &A, int B) 
{
    int n = A.size();
    int maxi = INT_MIN;
    int low = 0;
    int high = *max_element(A.begin(),A.end());
    int ans = 0;
    for(int i=0;i<n;i++){
        maxi = max(maxi,A[i]);
    }
    while(low <= high)
    {
        int mid = low + (high-low)/2;
        if(check(A,B,mid))
        {
            ans = mid;
            low = mid + 1;
        }
        else{
            high = mid-1;
        }
    }
    return ans;
}
