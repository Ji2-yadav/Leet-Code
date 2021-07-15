class Solution {
public:
    int mem[31] = {0};
    int fib(int n) {
    if(n==0) 
        return 0;
    if(n==1)
        return 1;
    if(mem[n]!=0)
        return mem[n];
    else
        mem[n] = fib(n-1) + fib(n-2);
    return mem[n];
        
    }
};