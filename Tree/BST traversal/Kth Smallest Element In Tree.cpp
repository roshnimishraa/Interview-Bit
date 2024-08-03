/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 void inorder(TreeNode* A, int &count, int &ans,int B)
 {
     if(A == NULL){
         return;
     }
     inorder(A->left, count, ans, B);
     count++;
     if(count == B){
         ans = A->val;
         return;
     }
     inorder(A->right, count, ans, B);
 }
int Solution::kthsmallest(TreeNode* A, int B) 
{
    int count=0;
    int ans;
    inorder(A,count,ans,B);
    return ans;
}
