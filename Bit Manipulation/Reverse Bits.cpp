bool findKthBitSet(int k, unsigned int A)
{
    if(((1 << (k-1)) & A)!=0) {
        return true;
    }
    return false;
}
unsigned int Solution::reverse(unsigned int A) {
  unsigned int ans=0;
  for(int i=1; i<=32; i++)
  {
      if(findKthBitSet(i,A)) //current bit is 1 
      {
        //   set a bit
          ans = 1 << (32-i) | ans;
      }
  }
  return ans;
}
