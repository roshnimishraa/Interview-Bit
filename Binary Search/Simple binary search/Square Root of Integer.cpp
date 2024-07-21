int Solution::sqrt(int A) {
    long long low=0;
    long long high = A;
    long long ans = 0;
    
    while(low <= high)
    {
        long long mid = low + (high - low)/2;
        long long val = mid*mid;
        if(val<= (long long)A)
        {
            // potential ans search for maximum potential ans
            ans = mid;
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }
    return ans;
}
