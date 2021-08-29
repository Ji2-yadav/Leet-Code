class Solution {
public:
   int lengthOfLongestSubstring(string s) {
        vector<int> mpp(256,-1);
        int left =0;
        int right =0;                               ////start left and right index at zero
        int n=s.size();
        int len =0;
        while(right<n)
        {
            if(mpp[s[right]] !=-1)                  /// check if char is repeated or not
            left=max(mpp[s[right]]+1,left);         ////IMPORTANT//jump left to the next index of repeated char
                
            mpp[s[right]]=right;                    /////update new location of char
            len=max(len,right-left+1);              ///check if new length is longer than previous length
            right++;                                /// move right forward
        }
        return len;
    }
};