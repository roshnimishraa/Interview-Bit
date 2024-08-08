/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 int helper(TreeNode* A, int B, int sum)
 {
     if(A == NULL) {
         return 0;
     }
     sum += A->val;
     
    //  left TreeNodeif
    if(A->left == NULL && A->right == NULL && sum == B){
        return 1;
    }
    
    int left=0, right = 0;
    if(A->left != NULL){
        left = helper(A->left, B, sum);
    }
    if(A->right != NULL){
        right = helper(A->right, B, sum);
    }
    return left || right;
 }
int Solution::hasPathSum(TreeNode* A, int B) {
    return helper(A,B,0);
}

