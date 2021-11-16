class Solution {
public:
    bool isSafe(vector<string> &board, int row, int col){
        // checking row
        for(int i = 0; i < row; ++i) {
            if(board[i][col] == 'Q') {
                return false;
            }
        }
        // check left diagonal
        int r = row-1, c = col-1;
        while(r >= 0 && c >= 0) {
            if(board[r--][c--] == 'Q') return false;
        }
        // check right diagonal
        r = row-1, c = col+1;
        while(r >= 0 && c < board.size()) {
            if(board[r--][c++] == 'Q') return false;
        }
        return true;
    }
    
    void solve(vector<vector<string>> &ans, vector<string> &board, int row, int target){
		//if we come to the last row check
        if(row == board.size()){
			//do we have queens left?
            if(target == 0){
				//if no push the answer
                ans.push_back(board);
            }
			//if queens are left return
            return;
        }
        for(int col=0; col < board.size(); col++){
			//checking if the location is safe
            if(isSafe(board, row, col)){
				//if safe put queen 
                board[row][col] = 'Q';
				//find recursive solution
                solve(ans, board, row + 1, target - 1);
				//backtrack
                board[row][col] = '.';
            }
        } 
        return;
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));  //initialize the string to '.'
        solve(ans, board, 0, n);
        return ans;
    }
};