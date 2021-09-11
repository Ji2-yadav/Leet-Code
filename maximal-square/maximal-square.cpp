class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int r=matrix.size(),c=matrix[0].size(),res=0;
        
        int dp[r][c];
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(i==0 || j==0){
                    dp[i][j]=matrix[i][j]-'0';
                    res=(matrix[i][j]=='1'?1:0); 
                    continue;
                }
                if(matrix[i][j]-'0'){
				//This is the heart of the problem. We check if the previous attached cells i.e.(i-1,j-1),(i-1,j) & (i,j-1) have a square i.e. they are equal to 1 
				//if not then 1 sqare will be formed since it is '1'
				//Then take the minimum of them and add the current cell as well. 
				//Doing this gives us just the side of a newly formed square!!
                    dp[i][j]=(min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]))==0)?1:(1+min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1])));
                }
                else{
                    dp[i][j]=0;
                }
                
            }
        }
              //Finding the mximum side  
            for(int i=0;i<r;i++)
            for(int j=0;j<c;j++)
                res=max(res,dp[i][j]);
		//returning the are which is asked in the question
        return res*res;
    }
};