class Solution {
public:
    int nthUglyNumber(int n) {
         long long i,j,val=1;
    if(n==1)return val;
	set<long long> s;
    s.insert(1);
    while(n--){
        val=*(s.begin());
        s.erase(val);
            s.insert(val*2);
            s.insert(val*3);
            s.insert(val*5);
        }
    return val;
    }
};