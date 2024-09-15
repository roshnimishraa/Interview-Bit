Time complexity: O(2^n * n)
Space complexity: O(n)

bool isPal(string &A)
{
    int left = 0 , right = A.size()-1;
    while(left < right)
    {
        if(A[left] != A[right]){
            return false;
  }
         left++;
         right--;
    }
    return true;
}

void helper(int index,string &A,vector<string> &output, vector<vector<string>> &ans)
{
    // base case 
    if(index == A.length()){
        ans.push_back(output);
        return;
    }
    string str;
    for(int i= index; i<A.length(); i++)
    {
      str += A[i];
      if(isPal(str)){
          output.push_back(str);
          helper(i+1,A, output, ans );
          output.pop_back();
      }
    }
}
vector<vector<string> > Solution::partition(string A) {
    vector<vector<string>> ans;
    vector<string> output;
    helper(0, A, output, ans);
    return ans;
}
