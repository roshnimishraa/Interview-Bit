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
vector<int> Solution::solve(TreeNode* A) {
    queue<TreeNode*> q;
    vector<int> ans;
    q.push(A);
    while(!q.empty()){
        int n = q.size();
        for(int i=0;i<n; i++){
            TreeNode* curr = q.front();
             ans.push_back(curr->val);
                    q.pop();
           if(curr->right != NULL)
            q.push(curr->right);
            if(curr->left != NULL)
            q.push(curr->left);
            
            
        }
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

Approach 2 
TC : O(N)
SC : O(N) 

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
     vector<vector<int>> ans;
     if(root == NULL) return {};
     queue<TreeNode*> q;
     q.push(root);
     while(!q.empty()){
        int n = q.size();
         vector<int> level;
        for(int i=0;i<n;i++){
               TreeNode* curr = q.front();
               q.pop();
        if(curr->left != NULL){
            q.push(curr->left);
        }
        if(curr->right != NULL){
            q.push(curr->right);
        }
        level.push_back(curr->val);
        
        } 
        ans.push_back(level);
     }   
     reverse(ans.begin(),ans.end());
     return ans;
    }
};
