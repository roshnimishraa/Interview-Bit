TC : O(N) 
SC : O(H) 

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 void reversePreorder(TreeNode* A, int level, vector<int> &ans)
 {
     if(A == NULL) return;
     if(ans.size() == level) {
         ans.push_back(A->val);
     }
     reversePreorder(A->right, level+1, ans);
     reversePreorder(A->left, level+1, ans);
 }
vector<int> Solution::solve(TreeNode* A) {
    vector<int> ans;
     reversePreorder(A, 0, ans);
     return ans;
}
