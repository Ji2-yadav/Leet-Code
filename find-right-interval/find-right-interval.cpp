class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        vector<pair<vector<int>,int>> temp,temp2;
        for(int i=0;i<intervals.size();i++)
        {
            temp.push_back(make_pair(intervals[i],i));
            temp2.push_back(make_pair(intervals[i],i));
        }
        sort(temp.begin(),temp.end());
        bool found;
        vector <int> ans(intervals.size());
        for(int i=0;i<temp.size();i++)
        {
            found = false;
            for(int j=i;j<temp.size();j++)
            {
                if(temp[j].first[0]>=temp[i].first[1])
                {
                    ans[temp[i].second]= temp[j].second;
                    found = true;
                    break;
                   
                }
                    
            }
            if(!found)
                ans[temp[i].second]=-1;
        }
        return ans;
    }
};