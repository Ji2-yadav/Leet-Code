class Solution {
public:
    vector<vector<char>> board;
    int row[9]={0};
    int col[9]={0};
    int subbox[9]={0};
    bool subboxcheck(int i)
    {
        if(subbox[i]==1)
            return true;
        else
        {
            int j,k;
            if(i==0)
                j=0,k=0;
            else if(i==1)
                j=0,k=3;
            else if(i==2)
                j=0,k=6;
            else if(i==3)
                j=3,k=0;
            else if(i==4)
                j=3,k=3;
            else if(i==5)
                j=3,k=6;
            else if(i==6)
                j=6,k=0;
            else if(i==7)
                j=6,k=3;
            else
                j=6,k=6;
            unordered_map<char,int> mp;
            for(int i1=j;i1<j+3;i1++)
                for(int j1=k;j1<k+3;j1++)
                    if(board[i1][j1]!='.')
                        mp[board[i1][j1]]++;
            
            for(auto it:mp)
            {
                if(it.second>1)
                    return false;
            }
            subbox[i]=1;
            return true;
          
        }
    }
    bool rowcheck(int i)
    {
        if(row[i]==1)
            return true;
        else
        {
            unordered_map<char,int> mp;
            for(int k=0;k<9;k++)
            {
                if(board[i][k]!='.')
                    mp[board[i][k]]++;
            }
            for(auto it:mp)
            {
                if(it.second>1)
                    return false;
            }
            row[i]=1;
            return true;
        }
    }
    bool colcheck(int i)
    {
        if(col[i]==1)
            return true;
        else
        {
            unordered_map<char,int> mp;
            for(int k=0;k<9;k++)
            {
                if(board[k][i]!='.')
                    mp[board[k][i]]++;
            }
            for(auto it:mp)
            {
                if(it.second>1)
                    return false;
            }
            col[i]=1;
            return true;
        }
    }
    int getbox(int i,int j)
    {
        if(i<3)
        {
            if(j<3)
                return 0;
            else if(j<6)
                return 1;
            else
                return 2;
        }
        else if(i<6)
        {
            if(j<3)
                return 3;
            else if(j<6)
                return 4;
            else
                return 5;
        }
        else
        {
            if(j<3)
                return 6;
            else if(j<6)
                return 7;
            else
                return 8;
        }
    }
    bool isValidSudoku(vector<vector<char>>& brd) {
       board = brd;
       for(int i=0;i<board.size();i++)
       {
           for(int j=0;j<board[i].size();j++)
           {
               if(board[i][j]!='.')
               {
                   if(rowcheck(i) && colcheck(j) && subboxcheck(getbox(i,j)))
                       continue;
                   else
                       return false;
               }
           }
       }
       return true;
    }
};