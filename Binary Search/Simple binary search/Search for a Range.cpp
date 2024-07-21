int firstOcc(const vector<int> &A, int target)
{
    int n = A.size();
    int low = 0, high = n-1;
    int first = -1;
    while(low <= high)
    {
        int mid = low + (high-low)/2;
        if(A[mid] == target){
           first = mid;
           high = mid-1;
        }
       else if(A[mid] < target){
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }
    return first;
}

int secondOcc(const vector<int> &A, int target)
{
    int n = A.size();
    int low=0, high=n-1;
    int second = -1;
    while(low <= high){
        int mid = low + (high-low)/2;
        if(A[mid] == target){
            second = mid;
            low = mid+1;
        }
        else if(A[mid] < target){
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }
    return second;
}
vector<int> Solution::searchRange(const vector<int> &A, int B) 
{
    int first = -1, second = -1;
     first = firstOcc(A,B);
     second = secondOcc(A,B);
  return {first,second};
  
}
