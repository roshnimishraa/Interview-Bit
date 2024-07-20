int upperBound(vector<int> &A, int x, int n)
{
    int low = 0, high = n-1;
    int ans = n;
    while(low <= high)
    {
        int mid = (low + high)/2;
    if(A[mid] > x) {
            ans = mid;
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    return ans;
}

int countSmallEqual(vector<vector<int>> &A, int m, int n, int x)
{
    int count = 0;
    for(int i=0;i<m;i++)
    {
        count += upperBound(A[i],x,n);
    }
    return count;
}

int Solution::findMedian(vector<vector<int> > &A) 
{
    int low = INT_MAX, high = INT_MIN;
    int n = A.size();
    int m = A[0].size();
    for(int i=0; i<m; i++)
    {
        low = min(low,A[i][0]);
        high = max(high, A[i][n-1]);
    }
    int req = (n*m)/2;
    while(low <= high)
    {
        int mid = (low + high)/2;
        int small = countSmallEqual(A,m,n,mid);
        if(small <= req)
        {
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }
    return low;
}
