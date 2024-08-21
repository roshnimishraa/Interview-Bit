/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
 TreeNode* helper(TreeNode* &A){
     if(A == NULL){
         return A;
     }
    //  post-order traversal 
    A->left = helper(A->left);
    A->right = helper(A->right);
    
    // leaf node 
    if(A->left == NULL && A->right == NULL){
        return A;
    }
    if(A -> left == NULL && A->right != NULL)
    {
        TreeNode* newNode = A->right;
        delete(A);
        return newNode;
    }
    if(A->right == NULL && A->left != NULL)
    {
        TreeNode* newNode = A->left;
        delete(A);
        return newNode;    
    }
    return A;
     }
TreeNode* Solution::solve(TreeNode* A) {
  return helper(A);
}
