/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 void helper(TreeNode* A, int B, vector<int> temp, int sum, vector<vector<int>> &ans)
 {
     if(A == NULL){
         return;
     }
     sum += A->val;
     temp.push_back(A->val);
     
     // Leaf Node 
     if(A->left == NULL && A->right == NULL)
     {
         if(sum == B)
         {
             ans.push_back(temp);
         }
         return;
     }
     helper(A->left, B, temp, sum, ans);
     helper(A->right, B, temp, sum, ans);
 }
vector<vector<int> > Solution::pathSum(TreeNode* A, int B) 
{
    vector<vector<int>> ans;
    vector<int> temp;
    int sum=0;
    helper(A, B, temp, sum, ans);
    return ans;
}
