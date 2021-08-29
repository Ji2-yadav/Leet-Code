class Solution {
public:
    bool checkInclusion(string s1, string s2) {
      if (s1.length() > s2.length()) return false;
        
        int cnt = s1.length();
        int s = 0, e = 0;
        vector<int> map(26,0);
        for (auto c : s1) map[c - 'a'] ++;
        
        while (e < s2.length()) {
            if (map[s2[e ++] - 'a']-- > 0) cnt --;
            if (e - s == s1.length() && cnt == 0) return true;
            if (e - s == s1.length() && map[s2[s ++] - 'a']++ >= 0) cnt++;
        }
        
        return false;   
    }
};