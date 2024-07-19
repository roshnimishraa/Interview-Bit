int Solution::searchMatrix(vector<vector<int> > &A, int B) 
{
    int n = A.size(), m = A[0].size();
    int low=0, high = n*m-1;
    while(low <= high)
    {
        int mid = low + (high-low)/2;
        int row = mid/m;
        int col = mid%m;
        if(A[row][col] == B){
            return true;
        }
        else if(A[row][col] < B)
        {
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }
    return false;
}
