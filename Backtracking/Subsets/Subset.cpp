Time complexity: O(2^n * n)
Space complexity: O(n)

void helper(int index,vector<int> &A, vector<int> &temp, vector<vector<int>> &ans)
{
    if(index == A.size()){
        ans.push_back(temp);
        return;
    }
    // include
      temp.push_back(A[index]);
      helper(index+1, A, temp, ans);
      temp.pop_back(); //backtracking
      
    // exclude
    helper(index+1, A, temp, ans);
}
vector<vector<int> > Solution::subsets(vector<int> &A) {
    vector<int> temp;
    vector<vector<int>> ans;
    sort(A.begin(), A.end());
     helper(0, A, temp, ans);
     sort(ans.begin(), ans.end());
     return ans;
}
