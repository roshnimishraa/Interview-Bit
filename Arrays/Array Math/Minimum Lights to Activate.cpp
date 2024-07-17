int Solution::solve(vector<int> &A, int B) 
{
    int n = A.size();
    int count = 0;
    int i=0;
    while(i<n){
        int right = min(i+B-1,n-1);
        int  left = max(i-B+1, 0);
        
        bool bulbFound = false;
        // find bulb within range 
        while(left <= right)
        {
            if(A[right] == 1){
                bulbFound = true;
                break;
            }
            right--;
        }
        if(!bulbFound) {
            return -1;
        }
        count++;
        // lights up neighbours 
         i = right + B;
         
    }
    return count;
}
