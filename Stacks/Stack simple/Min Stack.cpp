TC : O(1)
SC : O(2XN) 

stack<pair<int,int>> st;
MinStack::MinStack() {
    st = stack<pair<int,int>> ();
}

void MinStack::push(int x) {
    int mini;
    if(st.empty()){
        mini = x;
    }
    else{
        mini = min(st.top().second, x);
    }
    st.push({x, mini});
}

void MinStack::pop() 
{
    if (!st.empty()) {
            st.pop();
        }
}

int MinStack::top() {
  if (st.empty()) {
            return -1; 
        }
        return st.top().first;
}

int MinStack::getMin() {
       if (st.empty()) {
            return -1;
        }
        return st.top().second;
}

------------------------------------------------------------------------------------------------------------------------------------------------------------

Approach 2 : Optimize Space Complexity 

TC : O(1)
SC : O(N)

stack<long long> st;
long long mini;
MinStack::MinStack() {
    while(!st.empty()){
        st.pop();
    }
    mini = INT_MAX;
}

void MinStack::push(int x) {
    if(st.empty()){
        mini = x;
        st.push(x);
    }
    else{
        if(x < mini)
        {
            st.push(2*x*1LL - mini);
            mini = x;
        }
        else{
            st.push(x);
        }
    }
}

void MinStack::pop() {
    if(st.empty()) return;
    long long ele = st.top();
    st.pop();
    if(ele < mini)
    {
        mini = 2*mini - ele;
    }
}

int MinStack::top() {
    if(st.empty()) return -1;
long long ele = st.top();
if(ele < mini)
{
    return mini;
}
return ele;
}

int MinStack::getMin() {
     if (st.empty()) return -1;
    return mini;
}




