Time Complexity:O(2^n*k)
Space Complexity:O(k*x)

void helper(int index, vector<int> &A, int B, vector<int> &temp, vector<vector<int>> &ans)
{
    if(B == 0){
        ans.push_back(temp);
        return;
    }
    for(int i=index; i<A.size(); i++)
    {
        // duplicate [2,2]
        if(i> index && A[i] == A[i-1]){
            continue;
        }
        temp.push_back(A[i]);
        helper(i+1, A, B-A[i], temp, ans);
        temp.pop_back();
    }
}
vector<vector<int> > Solution::combinationSum(vector<int> &A, int B) {
    vector<vector<int>> ans;
    vector<int> temp;
    sort(A.begin(), A.end());
    helper(0, A, B, temp, ans);
    sort(ans.begin(), ans.end());
    return ans;
}
