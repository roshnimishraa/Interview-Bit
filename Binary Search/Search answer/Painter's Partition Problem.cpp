#include<bits/stdc++.h>

long long num(int mid, vector<int> &C) 
{
    long long boardPaint = 0, painters = 1;
    for (int i = 0; i < C.size(); i++)
     {
        if (boardPaint + C[i] <= mid)
         {
            boardPaint += C[i];
        } 
        else
         {
            painters++;
            boardPaint = C[i];
        }
    }
    return painters;
}

int Solution::paint(int A, int B, vector<int> &C) {
   
    long long result = -1;
    long long low = *max_element(C.begin(), C.end());
    if (C.size() < A) {
        return (low*B) % 10000003;
    }
 long long high = accumulate(C.begin(), C.end(), 0);
    while (low <= high)
     {
        
        long long mid = low + (high - low) / 2;
        
        if (num(mid, C) <= A)
         {
            result = (mid * B) % 10000003;
            high = mid - 1;
        } 
        else 
        {
            low = mid + 1;
        }
    }
    return result % 10000003;
}
