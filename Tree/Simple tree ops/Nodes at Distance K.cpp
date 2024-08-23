TC : O(N)
SC : O(N)


/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

 TreeNode* markParent(TreeNode* root, unordered_map<TreeNode*, TreeNode*> &parent_track, int target)
 {
     queue<TreeNode*> q;
     q.push(root);
     TreeNode* res;
     while(!q.empty()){
         TreeNode* node = q.front();
         q.pop();
         if(node->val == target){
             res = node;
         }
         if(node->left != NULL){
             q.push(node->left);
         parent_track[node->left] = node;
         }
         if(node->right != NULL){
             parent_track[node->right] = node;
             q.push(node->right);
         }
         
     }
     return res;
 }
vector<int> Solution::distanceK(TreeNode* A, int B, int C) {
    unordered_map<TreeNode*, TreeNode*> parent_track; //node->parent 
    TreeNode* target = markParent(A, parent_track, B);
    unordered_map<TreeNode*, bool> vis;
    queue<TreeNode*> q;
    q.push(target);
    vis[target] = true;
    int curr_level = 0;
    while(!q.empty()){
         int size = q.size();
       if(curr_level == C)
 {
     break;
 }
 curr_level++;
 
        for(int i=0; i<size;i++)
        {
            TreeNode* current = q.front();
            q.pop();
            
            if(current->left != NULL && !vis[current->left])
            {
                q.push(current->left);
                vis[current->left] = true;
            }
            if(current->right != NULL && !vis[current->right]){
                q.push(current->right);
                vis[current->right] = true;
            }
            if(parent_track[current] && !vis[parent_track[current]]){
                q.push(parent_track[current]);
                vis[parent_track[current]] = true;
            }
        }
    }
     vector<int> res;
     while(!q.empty())
     {
         TreeNode* current = q.front();
         q.pop();
         res.push_back(current->val);
     }
     return res;
}
