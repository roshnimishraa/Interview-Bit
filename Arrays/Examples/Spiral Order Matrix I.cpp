TC: O(N X M)
SC: O(N) 

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
    // placing pointers 
   int left = 0, top = 0;
   int right = m-1, bottom = n-1;
   vector<int> ans;
while(top <= bottom && left <= right)
{
    // print: right->bottom->left->top
// right
for(int i=left;i<=right;i++){
  ans.push_back(matrix[top][i]);
}
top++;
// bottom
for(int i=top;i<=bottom;i++){
    ans.push_back(matrix[i][right]);
}
right--;
if(top <= bottom)
{
// left 
for(int i=right;i>=left;i--)
{
 ans.push_back(matrix[bottom][i]);
}
bottom--;
}

// top
if(left <= right)
{
for(int i=bottom;i>=top;i--){
    ans.push_back(matrix[i][left]);
}
left++;
}
}
 return ans;
    }
};
