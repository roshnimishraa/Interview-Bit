TC : O(N) 
sC : O(log N) but in worst case it is O(h) 

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 void inorder(TreeNode* root,TreeNode* &first,TreeNode* &middle,TreeNode* &last,TreeNode* &prev)
 {
     if(root == NULL) return;
     inorder(root->left,first,middle,last,prev);
     if(prev != NULL && (root->val < prev->val))
     {
         if(first==NULL)
         {
             first = prev;
             middle = root;
         }
         else{
             last = root;
         }
     }
     prev = root;
     inorder(root->right,first,middle,last,prev);
 }
vector<int> Solution::recoverTree(TreeNode* A) 
{
    TreeNode* first;
    TreeNode* middle;
    TreeNode* last;
    TreeNode* prev;
    first = middle = last = NULL;
    prev = new TreeNode(INT_MIN);
    inorder(A,first,middle,last,prev);
    vector<int> ans;
    if(first && last)
    {
      ans.push_back(last->val);
        ans.push_back(first->val);
    }
    else if(first && middle)
    {
          ans.push_back(middle->val);
        ans.push_back(first->val);
    }
    return ans;
}
