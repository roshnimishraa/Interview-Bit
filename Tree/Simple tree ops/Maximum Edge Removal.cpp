Time Complexity: O(n) where n is number of nodes in tree.
Auxiliary Space: O(n)

int dfs(vector<int> adj[], int node, vector<int> &vis, int &count)
{
   vis[node] = 1;
    int currComponentNode = 0;
  for(auto it : adj[node])
  {
      if(!vis[it])
      {
          int subtreeNodeCount= dfs(adj, it, vis, count);
          
          if(subtreeNodeCount % 2 == 0){
              count++;
          }
          else{
              currComponentNode += subtreeNodeCount;
          }
      }
  }
  return (currComponentNode+1);
}
int Solution::solve(int A, vector<vector<int> > &B)
{
    vector<int> adj[A+1];
    for(int i=0; i<B.size(); i++)
    {
        int x = B[i][0];
        int y = B[i][1];
        
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    vector<int> vis(A+1, 0);
    
    int count = 0;
             
    dfs(adj, 1, vis, count);
    return count;
}
