Time complexity: O(4^n) n is the number of digits in the input number.Each digit of a number has 3 or 4 alphabets, so it can be said that each digit has 4 alphabets as options. for every recursion 4 more recursions are called (if it does not match the base case)

Space complexity: O(n)

void helper(int index, string &A, string output, string mapping[], vector<string> &ans)
{
    if(index == A.length()){
        ans.push_back(output);
        return;
    }
    int number = A[index]-'0';
    string values = mapping[number];
    for(int i=0; i<values.length(); i++)
    {
        output.push_back(values[i]);
        helper(index+1, A, output, mapping, ans);
        output.pop_back();
    }
    
}
vector<string> Solution::letterCombinations(string A) {
    vector<string> ans;
    string output="";
    string mapping[10]={"0","1","abc","def","ghi","jkl","mno","pqrs","tuv",
    "wxyz"};
    if(A.length() == 0){
        return ans;
    }
    helper(0,A,output, mapping, ans);
    return ans;
}
