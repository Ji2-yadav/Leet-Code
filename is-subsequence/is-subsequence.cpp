class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0;
        int j = 0;
        
        if(s == "") return true;
        
        while(j < t.length()) {
            if(t[j] == s[i]) {
                i++;
                if(i == s.length()) return true;
            }
            j++;
        }
        
        return false;
    }
};