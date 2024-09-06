TC : O(N)
SC : O(N)

Using stack

class Solution {
public:
    string simplifyPath(string path) {
        string token = "";
    stringstream ss(path);
    stack<string> st;
// tokenize
while(getline(ss, token, '/'))
{
 if(token=="." || token==""){
    continue;
 }
//  folder name
if(token != ".."){
    st.push(token);
}
else if(!st.empty()){
    // ..
    st.pop();
}
}

if(st.empty()) {
    // return root
    return "/";
}
string result="";
while(!st.empty())
{
    result = "/" + st.top()+result;
    st.pop();
}
return result;
    }
};


------------------------------------------------------------------------------------------------------------------------------------------------------------

Approach 2 : Using Vectors 
TC : O(N) 
SC : O(N) 

string Solution::simplifyPath(string A) {
    vector<string> vec;
    string token = "";
    stringstream ss(A);

    // Tokenize the string based on '/'
    while (getline(ss, token, '/')) {
        if (token == "" || token == ".") {
            continue; // Ignore empty and current directory tokens
        }
        // If it's not "..", we push it into the vector
        if (token != "..") {
            vec.push_back(token);
        }
        // If it's "..", we pop the last valid directory
        else if (!vec.empty()) {
            vec.pop_back();
        }
    }

    // If the vector is empty, return root "/"
    if (vec.empty()) {
        return "/";
    }

    // Construct the final path using manual string concatenation
    string res = "";
    for (int i = 0; i < vec.size(); ++i) {
        res += "/" + vec[i];
    }

    return res;
}
