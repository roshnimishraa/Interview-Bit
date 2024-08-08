TC : O(N) 
SC : O(N LOG N) 

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 int MOD = 1003;
 int solve(TreeNode* A, int curr)
 {
     if(A == NULL){
         return 0;
     }
     curr = (curr * 10 + A->val) % MOD;
    //  leaf node 
    if(A->left == NULL && A->right == NULL){
        return curr%MOD;
    }
    int left = solve(A->left, curr);
    int right = solve(A->right, curr);
    return (left + right)%MOD;
 }
int Solution::sumNumbers(TreeNode* A) {
    return solve(A, 0);
}

