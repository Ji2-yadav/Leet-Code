class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) { 
        sort(intervals.begin(),intervals.end());
        map <int,int> mp;
        vector<vector<int>> ans;
        for(int i=0;i<intervals.size();i++)
        {
            if(!mp.empty())
                if(mp.find(intervals[i][0])!=mp.end())
                {
                    mp[intervals[i][0]] = max(mp[intervals[i][0]],intervals[i][1]);

                    for (auto itr = mp.find(intervals[i][0]); itr != mp.end(); itr++) 
                    {
                        if(itr->first!=intervals[i][0])
                        {
                            if(itr->first <= mp[intervals[i][0]])
                            {
                                if(itr->second <=mp[intervals[i][0]])
                                    mp.erase(itr->first);
                                else
                                {
                                    mp[intervals[i][0]] = itr->second;
                                    mp.erase(itr->first);
                                    break;
                                }
                            }
                            else
                                break;
                        }
                    }
                }
                else
                {
                    auto it = mp.lower_bound(intervals[i][0]);
                    if(it!=mp.begin())
                    {
                        it--;
                        if(it->second >= intervals[i][0])
                        {
                            it->second = max(it->second,intervals[i][1]);
                            auto it2 = it;
                            it++;
                            while(it!=mp.end())
                            {
                                if(it->first <= it2->second)
                                {
                                    if(it->second <= it2->second)
                                        mp.erase(it->first);
                                    else
                                    {
                                        mp[it2->first] = it->second;
                                        mp.erase(it->first);
                                        break;
                                    }
                                }
                                else
                                    break;
                            }
                        }
                        else
                        {
                            mp[intervals[i][0]] = intervals[i][1]; 
                            auto itr = mp.find(intervals[i][0]);
                            auto itr2 = itr;
                            itr++;
                            while(itr!=mp.end())
                            {
                                if(itr->first <= itr2->second)
                                {
                                    if(itr->second <= itr2->second)
                                        mp.erase(itr->first);
                                    else
                                    {
                                        itr2->second = itr->second;
                                        mp.erase(itr->first);
                                        break;
                                    }
                                }
                                else 
                                    break;
                            }
                        }
                           
                    }
                    else
                    {
                        mp[intervals[i][0]] = intervals[i][1];
                        auto itr = mp.begin();
                        auto itr2 = itr;
                        itr++;
                        while(itr!=mp.end())
                        {
                            if(itr->first <= itr2->second)
                            {
                                if(itr->second <= itr2->second)
                                    mp.erase(itr->first);
                                else
                                {
                                    itr2->second = itr->second;
                                    mp.erase(itr->first);
                                    break;
                                }
                            }
                            else 
                                break;
                        }
                            
                    } 
                    
            }
            else
                mp[intervals[i][0]] = intervals[i][1];
            
            
            
        }
        for(auto x:mp)
            {
                vector<int> v1;
                v1.push_back(x.first);
                v1.push_back(x.second);
                
                ans.push_back(v1);
            }
            
        return ans;
    }
};