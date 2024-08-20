int Solution::minDepth(TreeNode* A) 
{
    if(A == NULL) return 0;
    // leaf node 
    if(A->left == NULL && A->right == NULL)
    {
        return 1;
    }
    int L = A->left!=NULL ? minDepth(A->left):INT_MAX;
    int R = A->right!=NULL ? minDepth(A->right):INT_MAX;
    return 1+min(L,R);
}
