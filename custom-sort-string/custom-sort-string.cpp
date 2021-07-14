class Solution {
public:
    string customSortString(string order, string str) {
        unordered_map<char,int> wcount;
        for(int i=0;i<str.size();i++)
        {
            wcount[str[i]]++;
        }
        string ans = "";
        for(int i=0;i<order.size();i++)
        {
            if(wcount.find(order[i])!=wcount.end())
            {
                for(int j=0;j<wcount[order[i]];j++)
                    ans.append(1,order[i]);
                wcount.erase(order[i]);
            }
        }
        for(auto x : wcount)
        {
            for(int i=0;i<x.second;i++)
                ans+=x.first;
        }
        return ans;
        
    }
};