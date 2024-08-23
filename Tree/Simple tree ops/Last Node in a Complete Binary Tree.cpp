/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int Solution::lastNode(TreeNode* A) {
    queue<TreeNode*> q;
    q.push(A);
    int last_node = 0;
    while(!q.empty()){
        TreeNode* front = q.front();
        last_node = front->val;
        q.pop();
        
        if(front->left != NULL){
            q.push(front->left);
        }
        if(front->right != NULL){
            q.push(front->right);
        }
    }
    return last_node;
}
