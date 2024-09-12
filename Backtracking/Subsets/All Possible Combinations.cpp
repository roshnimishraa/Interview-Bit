TC : O(k^n )
where n is the number of strings in A and k is the average length of the strings.
SC : O(n * k^n)
The n is for the recursion depth, and n.k^n is for storing the final result.

void helper(int i, int n, string &temp, vector<string> &A, vector<string> &ans)
{
    if(i == n){
        ans.push_back(temp);
        return;
    }
    // for every character of A[i]
    for(int j=0; j<A[i].size(); j++)
    {
        // add char to s and call for next element of add
        temp += A[i][j];
        helper(i+1, n, temp, A, ans);
        temp.pop_back();
    }
}

vector<string> Solution::specialStrings(vector<string> &A) {
   string temp;
    vector<string>ans;
    helper(0,A.size(),temp,A,ans);
    return ans;
}
