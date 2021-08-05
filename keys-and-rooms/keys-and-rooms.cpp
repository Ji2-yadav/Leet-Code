class Solution {
public:
    void checkroom(vector<vector<int>>& rooms,vector<int>& checked,int room)
    {
        if(checked[room]==1)
            return;
        checked[room]=1;
        for(int i=0;i<rooms[room].size();i++)
        {
            checkroom(rooms,checked,rooms[room][i]);
        }
        return;
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vector<int> checked(n,0);
        checkroom(rooms,checked,0);
                
        for(auto i:checked)
        {
            if (i==0)
                return false;
        }
        return true;
    }
};