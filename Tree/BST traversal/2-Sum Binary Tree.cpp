TC : O(N) 
SC : O(log N) ~ O(N) 
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 bool helper(TreeNode* A, int B, unordered_set<int> &st)
 {
     if(A == NULL) return false;
   int need = B - A->val;
   if(st.find(need) != st.end()) 
   return true;
   st.insert(A->val);
   
   return helper(A->left, B, st) || helper(A->right, B, st);
 }
int Solution::t2Sum(TreeNode* A, int B) {
    unordered_set<int> st;
    return helper(A, B, st);
}

Approach 2 
TC : O(N) 
SC : O(logN) ~ O(N) 
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 void inorder(TreeNode* A, int B,vector<int> &ans)
 {
   if(A == NULL) return;
   inorder(A->left, B,ans);
   ans.push_back(A->val);
   inorder(A->right, B,ans);
 }
int Solution::t2Sum(TreeNode* A, int B) {
  vector<int> ans;
  inorder(A, B, ans);
  int i=0, j = ans.size()-1;
  while(i < j){
    if(ans[i] + ans[j] == B)
    {
      return 1;
    }
    else if(ans[i] + ans[j] < B){
      i++;
    }
    else{
      j--;
    }
  }
  return 0;
}
