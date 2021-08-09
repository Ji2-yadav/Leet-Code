/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
   vector<TreeNode*> allPossibleFBT(int n) {
        vector<vector<TreeNode*>> dp;
        vector<TreeNode*> tmp;
        if (n%2 == 0)
            return tmp;
        for (int i=1; i<=n; i+=2) {
            tmp.clear();
            if (i==1) {
                TreeNode* tn = new TreeNode(0);
                tmp.push_back(tn);
                dp.push_back(tmp);
                continue;
            }
            for (int l=1; l<=i-2; l+=2) {
                int r = i-1-l;
                for (int j=0; j<dp[int((l-1)/2)].size(); j++) {
                    for (int k=0; k<dp[int((r-1)/2)].size(); k++) {
                        TreeNode* tn = new TreeNode(0, dp[int((l-1)/2)][j], dp[int((r-1)/2)][k]);
                        tmp.push_back(tn);
                    }
                }
            }
            dp.push_back(tmp);
        }
        return dp[int((n-1)/2)];
    }
};