TC : O(N)
SC : O(N)

int operate(int a, int b, string token)
{
    if(token=="+") return a+b;
    if(token== "-") return a-b;
    if(token=="*") return (long)a*(long)b;
    if(token=="/") return a/b;
    
    // dummy statement 
    return -1;
}
int Solution::evalRPN(vector<string> &A) 
{
    stack<int> st;
    for(int i=0;i<A.size();i++)
    {
         string ch = A[i];
        if(ch=="+" || ch=="-" || ch=="*" || ch=="/")
        {
            int b = st.top();
            st.pop();
            int a = st.top();
            st.pop();
            int res = operate(a,b, ch);
            st.push(res);
        }
        else{
            st.push(stoi(A[i]));
        }
    }
    return st.top();
}
