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

-----------------------------------------------------------------------------------------------------------------------------------------------------------

Approach 2 : Optimal 

Time Complexity: O(N)

Space Complexity: O(K)
    
vector<int> Solution::slidingMaximum(const vector<int> &A, int k)
{
    deque<int> dq;
    vector<int> ans;
    for(int i=0; i<A.size(); i++)
    {
        if(!dq.empty() && dq.front() == i-k)
        {
            dq.pop_front();
        }
        while(!dq.empty() && A[dq.back()] < A[i])
        {
            dq.pop_back();
        }
        dq.push_back(i);
        if(i >= k-1){
            ans.push_back(A[dq.front()]);
        }
    }
    return ans;
}

