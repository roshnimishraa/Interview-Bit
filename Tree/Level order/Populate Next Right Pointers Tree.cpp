TC: O(N)
SC: O(N)

/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
 
 void helper(TreeLinkNode* A)
 {
   if(A== NULL) return;
   queue<TreeLinkNode*> q;
   q.push(A);
   q.push(NULL);
   while(!q.empty())
   {
     TreeLinkNode* curr = q.front();
     q.pop();
     if(curr == NULL)
     {
       if(!q.empty()){
         q.push(NULL);
       }
       else{
         return; 
       }
     }
     else{
       TreeLinkNode* nextAddress = q.front();
       curr->next = nextAddress;
       if(curr->left != NULL)
       q.push(curr->left);
       if(curr->right != NULL)
       q.push(curr->right);
     }
   }
 }
void Solution::connect(TreeLinkNode* A) {
  helper(A);
}
