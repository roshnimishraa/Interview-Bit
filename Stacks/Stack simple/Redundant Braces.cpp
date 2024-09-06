bool isOperator(char ch)
{
return (ch == '+' || ch=='-' || ch=='*' || ch=='/');
}

int Solution::braces(string A) {
    stack<char> st;
    for(int i=0; i<A.length(); i++)
    {
        char ch = A[i];
        if(ch== '(' || isOperator(ch))
        {
            st.push(ch);
        }
        
        else if(ch == ')')
        {
            if(st.top() == '(') return true;
            
            else {
                while(isOperator(st.top())){
                    st.pop();
                }
                st.pop();
            }
        }
    }
    return false;
}
