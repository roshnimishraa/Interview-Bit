vector<int> Solution::solve(TreeNode* A, int B) {
    vector<int> ans;
    queue<TreeNode *> q;
    q.push(A);
    bool foundB = true;
    while(!q.empty() && foundB){
        int n=q.size();
        for(int i=0;i<n;i++){
            TreeNode *curr=q.front();
            q.pop();
            if( (curr->left   && curr->left->val== B) || (curr->right && curr->right->val==B))
 foundB=false;
            else {
            if(curr->left) q.push(curr->left);
            if(curr->right) q.push(curr->right);
            }
        }
    }
    while(!q.empty()){
        ans.push_back(q.front()->val);
        q.pop();
    }
    return ans;
}
