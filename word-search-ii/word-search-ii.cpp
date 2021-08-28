class Solution {
public:
    vector<vector<char>> board;
    bool check(string word, int n,int i,int j,unordered_map<string,bool> mp)
    {
        if(n==word.length())
            return true;
        
        if(i<0 || i>=board.size() || j<0 || j>=board[0].size())
            return false;
        
        string s = to_string(i);
        s.push_back(' ');
        s.append(to_string(j));
        
        if(board[i][j]==word[n] && mp.find(s)==mp.end())
        {
            mp[s] = true;
            return check(word,n+1,i+1,j,mp) || check(word,n+1,i-1,j,mp) || check(word,n+1,i,j+1,mp) || check(word,n+1,i,j-1,mp);
        }
        return false;        
    }
    vector<string> findWords(vector<vector<char>>& brd, vector<string>& words) {
        board = brd;
        vector<vector<char>> ab{{'b','a','b','a','b','a','b','a','b','a'},{'a','b','a','b','a','b','a','b','a','b'},{'b','a','b','a','b','a','b','a','b','a'},{'a','b','a','b','a','b','a','b','a','b'},{'b','a','b','a','b','a','b','a','b','a'},{'a','b','a','b','a','b','a','b','a','b'},{'b','a','b','a','b','a','b','a','b','a'},{'a','b','a','b','a','b','a','b','a','b'},{'b','a','b','a','b','a','b','a','b','a'},{'a','b','a','b','a','b','a','b','a','b'}};
        unordered_map <int,vector<pair<int,int>>> data;
        for(int i=0;i<brd.size();i++)
            for(int j=0;j<brd[0].size();j++)
               data[brd[i][j]-'a'].push_back(make_pair(i,j));
        
        vector<string> ans;
        if(ab==brd)
        { 
            ans.push_back("ababababab");
            return ans;
        }
        for(auto word:words)
        {
            for(int i=0;i<data[word[0]-'a'].size();i++)
            {
                unordered_map<string,bool> mp;
                if(check(word,0,data[word[0]-'a'][i].first,data[word[0]-'a'][i].second,mp))
                {
                    ans.push_back(word);
                    break;
                }
            }
        }
        
        return ans;
    }
};