TC : O(N) + O(N) ~ O(N)  if ordered map ~ O(N log N) 
SC : O(N) + O(N) ~ O(N) 
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
 TreeNode* createParentMapping(TreeNode* root, int target, map<TreeNode*, TreeNode*> &nodeToParent)
 {
     TreeNode* res = NULL;
     queue<TreeNode*> q;
     q.push(root);
     nodeToParent[root] = NULL;
     while(!q.empty())
     {
         TreeNode* front = q.front();
         q.pop();
         if(front->val == target)
         {
             //target node mapping start
             res = front;
         }
         if(front->left != NULL)
         {
             nodeToParent[front->left] = front;
             q.push(front->left);
         }
         if(front->right != NULL)
         {
             nodeToParent[front->right] = front;
             q.push(front->right);
         }
         
     }
     return res;
 }
 
 int burnTree(TreeNode* root, map<TreeNode*, TreeNode*> &nodeToParent)
 {
     map<TreeNode*, bool> vis;
     queue<TreeNode*> q;
     q.push(root);
     vis[root] = true;
     int ans=0;
    
     while(!q.empty())
     {
         int flag = 0; // check if there is change 
         int size = q.size(); 
         for(int i=0;i<size;i++)
         {
            //  process neighbouring node
            TreeNode* front = q.front();
            q.pop();
            if(front->left != NULL && !vis[front->left])
            {
                flag = 1;
                q.push(front->left);
                vis[front->left] = true;
            }
            if(front->right != NULL && !vis[front->right])
            {
                flag = 1;
                q.push(front->right);
                vis[front->right] = true;
            }
            if(nodeToParent[front] != NULL && !vis[nodeToParent[front]])
            {
                flag = 1;
                q.push(nodeToParent[front]);
                vis[nodeToParent[front]] = true;
            }
         }
         if(flag == 1){
             ans++;
         }
     }
     return ans;
 }
int Solution::solve(TreeNode* A, int B) {
    // algo
    // 1. Create Node To Parent Mapping 
    // 2. Find target Node
    // 3. Burn the tree in min time

    map<TreeNode*, TreeNode*> nodeToParent;
    TreeNode* targetNode = createParentMapping(A, B, nodeToParent);
    
  int ans=  burnTree(targetNode, nodeToParent);
    return ans;
}
