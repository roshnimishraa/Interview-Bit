Time complexity: O(2^t * k) where t is the target, k is the average length

Space complexity: O(k*x), where k is the average length and x is the no. of combinations

class Solution {
public:
void helper(int index,vector<int> &nums,int target,vector<int> &output,vector<vector<int>> &ans)
{
    // base case 
     if(index > nums.size()){
return;
    } 

if(index == nums.size()) {
    if(target == 0){
        ans.push_back(output);
      
    }
      return;
}

// include condition target >= nums[index]
if(nums[index] <= target)
{
output.push_back(nums[index]);
// given same no. can be chosen unlimited of times
helper(index,nums,target-nums[index],output,ans);
output.pop_back();
}
// exclude
helper(index+1,nums,target,output,ans);
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
 vector<vector<int>> ans;
     vector<int> output;

helper(0,candidates,target,output,ans);
return ans;   
    }
};
