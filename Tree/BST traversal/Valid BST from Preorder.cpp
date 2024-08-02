#include<bits/stdc++.h>
int Solution::solve(vector<int> &A) {
     int root = INT_MIN;
    stack<int> st;
 for(int i=0;i<A.size();i++)
 {
     while(!st.empty() && A[i] > st.top())
     {
         root = st.top();
         st.pop();
     }
     if(A[i] < root){
         return 0;
     }
     st.push(A[i]);
 }
 return 1;
}

