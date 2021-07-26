class Solution {
public:
    int minOperations(int n) {
        if(n%2!=0)
            return (((n+1)/2)-1)*(1 + ((n+1)/2)-1);

        else
            return ((n/2)-1)*(1+((n/2)-1)) + (n/2);
      
        return 0;
    
    }
};