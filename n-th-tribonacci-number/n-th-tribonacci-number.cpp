class Solution {
public:
    int mem[38]= {0};
    int tribonacci(int n) {
        if(n==0)
            return 0;
        if(n==1)
            return 1;
        if(n==2)
            return 1;
        if(mem[n]!=0)
            return mem[n];
        else
            mem[n] = tribonacci(n-3) + tribonacci(n-2) +tribonacci(n-1);
        return mem[n];
    }
};