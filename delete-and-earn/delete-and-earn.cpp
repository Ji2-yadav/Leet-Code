class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
       int max_e = *max_element(nums.begin(), nums.end());
        int n = 10001;
        vector<int> freq(n);
        for(int num : nums){
            freq[num]++;
        }
        int dp[n];
        dp[1] = freq[1];
        dp[2] = max(dp[1], freq[2]*2);
        for(int i =3; i<=max_e; i++){
            dp[i] = max(dp[i-1], dp[i-2]+ i*freq[i]);
        }
        return dp[max_e];
    }
};