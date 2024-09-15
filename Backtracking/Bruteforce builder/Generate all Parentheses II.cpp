Time complexity: O(2^N)
Space complexity: O(N)

void solve(int A, string curr, int open, int close, vector<string> &ans)
{
  if(curr.length() == 2*A)
  {
  ans.push_back(curr);
  return;
  }
  if(open < A)
  {
      curr.push_back('(');
      solve(A, curr, open+1, close, ans);
      curr.pop_back();
  }
  
  if(close < open)
  {
      curr.push_back(')');
      solve(A, curr, open, close+1, ans);
      curr.pop_back();
  }
  
}

vector<string> Solution::generateParenthesis(int A) {
    vector<string> ans;
    string curr="";
    int open=0;
    int close=0;
    solve(A, curr, open, close,ans);
    return ans;
}
