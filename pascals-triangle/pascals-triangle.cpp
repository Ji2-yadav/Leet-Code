class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> sol;
        for(int i=0;i<numRows;i++)
        {
            vector<int> v1;
            for(int j=0;j<=i;j++)
            {
                if(j==0 || j==i)
                    v1.push_back(1);
                else
                    v1.push_back(sol[i-1][j-1]+sol[i-1][j]);     
            }
            sol.push_back(v1);
        }
        return sol;
    }
};