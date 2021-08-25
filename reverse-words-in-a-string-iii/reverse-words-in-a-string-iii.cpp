class Solution {
public:
    string reverseWords(string s) {
            
        int l = 0, r = 0, a = 0; 
        
        for(int i = 0; i < s.size(); i++){
            
            if(s[i] == 32 || i == s.size()-1){ // 32 = ASCII for Space & Second condition for last word of string.
                l = a; // We tell when the word starts
                r = i == s.size() - 1 ? i : i-1; // If it is the last word, right pointer to end, if not, one less than space
                
                while(l<r){ // Reverse word 
                    char aux = s[l];
                    s[l++] = s[r];
                    s[r--] = aux;
                }
                a = i+1; // Store when the next word starts for L
            }
        }
        
        return s;
    }
};