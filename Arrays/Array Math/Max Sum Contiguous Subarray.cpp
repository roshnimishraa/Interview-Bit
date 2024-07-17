using namespace std;
int Solution::maxSubArray(const vector<int> &arr) {
    int n = arr.size();
    int maxSum = INT_MIN;
    int sum=0;
    for(int i=0;i<n;i++){
        sum += arr[i];
       maxSum = max(maxSum,sum);
       if(sum < 0){
           sum = 0;
       }
    }
    return maxSum;
}
