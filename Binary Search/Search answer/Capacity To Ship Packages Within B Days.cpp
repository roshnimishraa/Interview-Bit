#include<bits/stdc++.h>
int daysRequired(vector<int> &A, int cap)
{
    int days = 1;
    int load = 0;
    int n = A.size();
    for(int i=0;i<n;i++)
    {
        if(load + A[i] > cap) // go to next day
        {
            days+=1;
            load = A[i]; //load to next day
        }
        else{
            // if cap is not exceeding then load into same day
            load += A[i];
        }
    }
    return days;
}
int Solution::solve(vector<int> &A, int B) 
{
    int low = *max_element(A.begin(),A.end());
    int high = accumulate(A.begin(), A.end(), 0);
    int ans=0;
     while(low <= high)
     {
         int mid = low + (high - low)/2;
         int noOfDays = daysRequired(A, mid);
         if(noOfDays <= B)
         {
             ans = mid;
            high = mid-1;
         }
         else{
             low = mid+1;
         }
     }
     return ans;
}
