TC : O(N) 
SC : O(N LOG N) high of binary tree  recursion stack

int Solution::maxDepth(TreeNode* A) {
    if(A == NULL) return 0;
    int left = maxDepth(A->left);
    int right = maxDepth(A->right);
    return max(left,right)+1;
}
