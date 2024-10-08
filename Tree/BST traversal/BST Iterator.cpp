TC : O(1) 
SC : O(h)
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

stack<TreeNode*> st;
BSTIterator::BSTIterator(TreeNode *root) {
 while(root != NULL)
 {
     st.push(root);
     root= root->left;
 }
}

// void pushAll(TreeNode* root)
// {
//     for(;root != NULL; st.push(root), root= root->left);
// }
/** @return whether we have a next smallest number */
bool BSTIterator::hasNext() {
return !st.empty();
}

/** @return the next smallest number */
int BSTIterator::next() {
TreeNode* temp= st.top();
st.pop();
BSTIterator(temp->right);
return temp->val;
}

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
