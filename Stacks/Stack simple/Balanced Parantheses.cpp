Time Complexity: O(n)
Space Complexity: O(n)
  
bool matches(char ch, char top)
{
 if((ch==')') && top=='('){
     return true;
 }
 else{
     return false;
 }
}
int Solution::solve(string A) {
    stack<char> st;
 for(int i=0; i<A.size(); i++){
     char ch = A[i];
    //  if open bracket
    if(ch == '('){
        st.push(ch);
    }
    else{
        if(st.empty()) return 0;
    char top = st.top();
    st.pop();
if(matches(ch,top) == true){
continue;
}
else return 0;
    }
 }
 return st.empty();
}

