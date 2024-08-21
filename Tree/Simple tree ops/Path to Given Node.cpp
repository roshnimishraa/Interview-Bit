/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 bool getPath(TreeNode *root,vector<int> &arr,int x)
 {
  if(root == NULL)
   return false;
  arr.push_back(root->val);
  if(root->val == x)
   return true;
  if(getPath(root->left,arr,x) || getPath(root->right,arr,x))    
  return true;
  
  arr.pop_back(); //backtracking
  return false;
 }
vector<int> Solution::solve(TreeNode* A, int B) 
{
  vector<int> ans;
  if(A == NULL)  return ans;
  getPath(A,ans,B);
  return ans; 
}
