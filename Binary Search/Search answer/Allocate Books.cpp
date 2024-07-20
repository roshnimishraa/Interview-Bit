#include<bits/stdc++.h>

int countStu(vector<int> &A, int pages)
{
    int n = A.size();
    int stu = 1, pageStu = 0;
  for(int i=0;i<n;i++)
  {
        if(A[i] + pageStu <= pages)
    {
        pageStu += A[i];
    }
    else{
        stu++;
        pageStu = A[i];
    }
  }
//   return no. of student
return stu;
}
int Solution::books(vector<int> &A, int B)
{
    if(B > A.size())
    {
        return -1;
    }
    int low = *max_element(A.begin(),A.end());
    int high = accumulate(A.begin(),A.end(),0);
    int ans = 0;
    while(low <= high)
    {
        int mid = (low + high)/2;
        int noOfStudents = countStu(A,mid);
        if(noOfStudents > B)
        {
            low = mid + 1;
        }
        else{
            ans = mid;
            high = mid-1;
        }
    }
    return ans;
}
