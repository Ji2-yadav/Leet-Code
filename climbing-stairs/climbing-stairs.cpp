class Solution {
public:
int climbStairs(int n) {
      int j=1,k=2,l;
     j = 1;
     if(n==1)
         return j;
     else if(n==2)
         return k;
    for(int i=2;i<n;i++)
    {
      l = j + k;
      j = k;
      k = l;
    }
    return l;
}
};