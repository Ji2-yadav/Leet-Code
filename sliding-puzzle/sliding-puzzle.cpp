class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
	unordered_set<string> seen;
	queue<string> todo;
	vector<vector<int>> moves = {{1,3},{0,2,4},{1,5},{0,4},{1,3,5},{2,4}};
	string str;
	int step=-1;

	for(int i=0; i<board.size(); i++)
		for(int j=0; j<board[0].size(); j++)
			str+=to_string(board[i][j]);

	todo.push(str);
	while(todo.size()){
		step++;
		int n=todo.size();
		while(n--){
			auto& cur=todo.front();
			if(cur=="123450") 
				return step;
			seen.insert(cur);
			int pos=cur.find('0');
			for(auto i: moves[pos]){
				swap(cur[pos], cur[i]);
				if(seen.count(cur)==0) 
					todo.push(cur);
				swap(cur[pos], cur[i]);
			}
			todo.pop();
		}
	}
	return -1;
}
};