class Solution {
public:
    long long find (multiset <pair<int,int>> &line)
    {
        int t=-1;
        int s=0;
        long long res=0;
        for(auto x: line)
        {
            if(s==0)
                t=x.first;
            s+=x.second;
            if(s==0)
            {
                res+=x.first-t;
            }
        }
        return res;
    }
    int rectangleArea(vector<vector<int>>& rectangles) {
        int n =rectangles.size();
        vector<vector<int>>v;
        long long mod =1e9 +7;
        for(auto x: rectangles)
        {
            v.push_back({x[1],1,x[2],x[0]});
            v.push_back({x[3],0,x[2],x[0]});
        }
        sort(v.begin(),v.end());
        int t=v[0][0];
        multiset <pair<int,int>> line;
        long long res=0;
        for(int i=0;i<2*n;i++)
        {
            if(v[i][1]==1)
            {
                if(v[i][0]==t)
                {
                    line.insert(make_pair(v[i][3],-1));
                    line.insert(make_pair(v[i][2],1));
                }
                else
                {
                    res =(res+((v[i][0]-t)*find(line)))%mod;
                    t=v[i][0];
                    line.insert(make_pair(v[i][3],-1));
                    line.insert(make_pair(v[i][2],1));
                    
                }
            }
            else
            {
                if(v[i][0]==t)
                {
                    line.erase(line.find(make_pair(v[i][3],-1)));
                    line.erase(line.find(make_pair(v[i][2],1)));
                }
                else
                {
                    res =(res+((v[i][0]-t)*find(line)))%mod;
                    t=v[i][0];
                    line.erase(line.find(make_pair(v[i][3],-1)));
                    line.erase(line.find(make_pair(v[i][2],1)));
                    
                }
                
                
            }
            
            
        }
        return res;
        
    }
};