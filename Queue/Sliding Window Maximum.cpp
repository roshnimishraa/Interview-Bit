Approach 1 : Brute Force 

Time Complexity: O(N^2)
Reason: One loop for traversing and another to findMax

Space Complexity: O(K) 
Reason: No.of windows

void getMax(const vector<int> &A, int l, int r, vector<int> &arr)
{
    int maxi = INT_MIN;
    for(int i = l; i <= r; i++)
    {
        maxi = max(A[i], maxi);
    }
    arr.push_back(maxi); 
}

vector<int> Solution::slidingMaximum(const vector<int> &A, int B) 
{
    int left = 0, right=0;
    int maxi = INT_MIN;
    vector<int> ans;
    int i, j;
    while(right < B-1)
    {
        right++;
    }
    while(right < A.size())
    {
        getMax(A, left, right, ans);
        left++;
        right++;
    }
    return ans;
}
