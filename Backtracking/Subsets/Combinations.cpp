Time Complexity (TC): O(( B^A)) – generating all combinations of B elements from A. 
Space Complexity (SC): 𝑂 (𝐵) – depth of recursion and space to store temporary combinations.

void helper(int index, int A, int B, vector<int> &temp, vector<vector<int>> &ans)
{
    if(B == 0){
        ans.push_back(temp);
        return;
    }
    if (index > A) return;
    // include
    temp.push_back(index);
    helper(index+1, A, B-1, temp, ans);
    temp.pop_back();
    
    // exclude
    helper(index+1, A, B, temp, ans);
}
vector<vector<int> > Solution::combine(int A, int B) {
    vector<vector<int>> ans;
    vector<int> temp;
    helper(1, A, B, temp, ans);
    return ans;
}
