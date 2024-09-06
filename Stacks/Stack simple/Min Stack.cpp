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




