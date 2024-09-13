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
while(index+1 < A.size() && A[index] == A[index+1])
{
    index++;
}
    helper(index+1, A, temp, ans);
}

vector<vector<int> > Solution::subsetsWithDup(vector<int> &A) {
    vector<vector<int>> ans;
    vector<int> temp;
    sort(A.begin(), A.end());
    helper(0, A, temp, ans);
sort(ans.begin(), ans.end());
return ans;
}
