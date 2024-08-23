/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int Solution::consecutiveNodes(TreeNode* A) {
    queue<TreeNode*> q;
    q.push(A);
    int ans=0;
    while(!q.empty()){
        TreeNode* curr = q.front();
        q.pop();
        
        if(curr->left != NULL){
            if(abs(curr->val - curr->left->val) == 1) 
            ans++;
            q.push(curr->left);
        }
        if(curr->right != NULL){
            if(abs(curr->val - curr->right->val) == 1) ans++;
            q.push(curr->right);
        }
    }
    return ans;
}
