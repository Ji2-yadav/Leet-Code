class NumMatrix {
private:
	vector<vector<int>>dp;
public:
    NumMatrix(vector<vector<int>>& matrix): dp(matrix.size(), vector<int>(matrix[0].size())) {
        int i, j;
		int rows = matrix.size();
		int cols = matrix[0].size();
		dp[0][0] = matrix[0][0];
        for(i = 1; i < rows; i++){
            dp[i][0] = dp[i - 1][0] + matrix[i][0];
        }
        for(i = 1; i < cols; i++){
            dp[0][i] = dp[0][i - 1] + matrix[0][i];
        }
        for(i = 1; i < rows; i++){
            for(j = 1; j < cols; j++){
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1] + matrix[i][j];
                dp[i][j] -= dp[i - 1][j - 1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int x = dp[row2][col2];
        int y = row1 >= 1 ? dp[row1 - 1][col2] : 0;
        int z = col1 >= 1 ? dp[row2][col1 - 1] : 0;
        int w = row1 >=1 && col1 >=1 ? dp[row1 - 1][col1 -1] : 0;
        return x - y - z + w;
    }
};
