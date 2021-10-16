class Solution {
public:
    string fractionAddition(string expression) {
        
        if(expression.empty()) return "";
        int n = expression.size();
        vector<int> numerator, denominator;
        int flag=1, i=0, ultimateDeno=1;
        if(expression[0]=='-') {
            flag = -1;
            i++;
        }
        
        while(i<n) {
            int numer=0, denom=0;
            while(isdigit(expression[i])) {
                numer = numer*10 + expression[i++]-'0';
            }
            i++;
            while(i<n && isdigit(expression[i])) {
                denom = denom*10 + expression[i++]-'0';
            }
            numerator.push_back(flag*numer);
            denominator.push_back(denom);
            if(ultimateDeno % denom != 0) ultimateDeno *= denom;
            if(i<n && expression[i]=='-') flag = -1;
            else flag = 1;
            i++;
        }
        
        int ultimateNume = 0;
        n = numerator.size();
        for(int i=0; i<n; i++) {
            ultimateNume += numerator[i] * (ultimateDeno/denominator[i]);
        }
        
        int temp = __gcd(abs(ultimateNume), ultimateDeno);
        ultimateNume /= temp;
        ultimateDeno /= temp;
        
        return to_string(ultimateNume) + '/' + to_string(ultimateDeno);
    }
};