Approach 1 : Recursion
  
Time Complexity:  N! x N
Space Complexity:  O(N)
 
void helper(vector<int> &A, int freq[], vector<int> &ds, vector<vector<int>> &ans)
{
    if(ds.size() == A.size()){
        ans.push_back(ds);
        return;
    }
    for(int i=0; i<A.size(); i++)
    {
        if(freq[i] ==0){
            freq[i] = 1;
            ds.push_back(A[i]);
            helper(A, freq, ds, ans);
            freq[i] = 0;
            ds.pop_back();
        }
    }
}

vector<vector<int> > Solution::permute(vector<int> &A) {
    vector<vector<int>> ans;
    vector<int> ds;
//freq[A.size]-> if it is unmarked then it means it has not been picked and then we pick and make 
// sure it is marked as picked.
    int freq[A.size()] = {0}; 
    helper(A, freq, ds, ans);
    return ans;
}

--------------------------------------------------------------------------------------------------------------------------------------------------------

Approach 2 : Backtracking 

Time Complexity: O(N! X N)
Space Complexity: O(1)
  
void helper(int index, vector<int> &A, vector<vector<int>> &ans)
{
    if(index == A.size())
    {
        ans.push_back(A);
        return;
    }
    for(int i=index; i<A.size(); i++)
    {
        swap(A[index], A[i]);
        helper(index+1, A, ans);
        swap(A[index], A[i]);
        
    }
}
vector<vector<int> > Solution::permute(vector<int> &A) {
    vector<vector<int>> ans;
    helper(0, A, ans);
    return ans;
}



  
