class Solution {
public:
    void reverseStr(string& str)
{
    int n = str.length();
 
    // Swap character starting from two
    // corners
    for (int i = 0; i < n / 2; i++)
        swap(str[i], str[n - i - 1]);
}
     int LCS(string text1, string text2) {
        int n = text1.length();
        int m = text2.length();
        
        vector<vector<int>> t (n+1,vector<int> (m+1,0));
        
        for(int i=1;i<n+1;i++)
            for(int j=1;j<m+1;j++)
                if(text1[i-1] == text2[j-1])
                    t[i][j] = 1 + t[i-1][j-1];
                else
                    t[i][j] = max(t[i-1][j], t[i][j-1]);
        
        return t[n][m];
            
    }
    int longestPalindromeSubseq(string s) {
        string s2 = s;
        reverseStr(s2);
        return LCS(s,s2);
    }
};