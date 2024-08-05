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
vector<vector<int> > Solution::zigzagLevelOrder(TreeNode* A) {
    vector<vector<int>> ans;
    if(A == NULL) return ans;
    queue<TreeNode*> q;
    q.push(A);
    bool LeftToRight = true; 
    while(!q.empty()){
        vector<int> level;
        int n = q.size();
        for(int i=0;i<n;i++){
            TreeNode* curr = q.front();
            q.pop();
            level.push_back(curr->val);
      
            if(curr->left != NULL)
                q.push(curr->left);
            
            if(curr->right != NULL)
                q.push(curr->right);
            
        }
        LeftToRight = !LeftToRight; //after every level iteration switching flag from 0->1 || 1->0
        if(LeftToRight == true)
        {
            reverse(level.begin(), level.end()); 
        }
        ans.push_back(level);
    }
    return ans;
}


Approach 2:
level = 1 based indexing

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<vector<int> > Solution::zigzagLevelOrder(TreeNode* A) {
    vector<vector<int>> ans;
    if(A == NULL) return ans;
    int LevelCount =0;
    queue<TreeNode*> q;
    q.push(A);
  
    while(!q.empty()){
        vector<int> level;
        int n = q.size();
        LevelCount++;
        for(int i=0;i<n;i++){
            TreeNode* curr = q.front();
            q.pop();
            level.push_back(curr->val);
      
            if(curr->left != NULL)
                q.push(curr->left);
            
            if(curr->right != NULL)
                q.push(curr->right);
            
        }
       if(LevelCount % 2 != 0){
           ans.push_back(level);
       }
       else{
           reverse(level.begin(),level.end());
           ans.push_back(level);
       }
    }
    return ans;
}

