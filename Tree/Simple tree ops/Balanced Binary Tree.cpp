TC : O(N) 
SC : O(N) + O(H) 

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
 int dfsHeight(TreeNode* A){
     if(A == NULL) return 0;
     int leftH = dfsHeight(A->left);
     if(leftH == -1) return -1;
     
     int rightH = dfsHeight(A->right);
     if(rightH == -1) return -1;
     
     if(abs(leftH - rightH) > 1)  return -1;
     return max(leftH, rightH) + 1;
 }
int Solution::isBalanced(TreeNode* A) {
  return dfsHeight(A) != -1;
}
