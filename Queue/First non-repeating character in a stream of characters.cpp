Time Complexity: O(n)
Space Complexity: O(n)

string Solution::solve(string A) {
    unordered_map<char, int> count;
    queue<int> q;
    string ans = "";
    for(int i=0; i<A.length(); i++)
    {
        char ch = A[i];
        count[ch]++;
        q.push(ch);
        while(!q.empty())
        {
            // repeating character
            if(count[q.front()] > 1){
                q.pop();
            }
            else{
                // non-repeating character
                ans.push_back(q.front());
                break;
            }
        }
        if(q.empty()){
            ans.push_back('#');
        }
    }
    return ans;
}
