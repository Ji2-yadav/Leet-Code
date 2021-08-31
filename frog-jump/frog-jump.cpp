class Solution {
public:
    unordered_map<int,bool> mp;
    unordered_map<string,bool> mp2;

    bool jump(vector<int>& stones, int pos,int k){
        if(k<=0 || pos> stones[stones.size()-1])
            return false;
        if(mp.find(pos)==mp.end())
            return false;
        if(pos== stones[stones.size()-1])
            return true;
        string s = to_string(pos);
        s.push_back(' ');
        s.append(to_string(k));
        
        if(mp2.find(s)!=mp2.end())
            return mp2[s];
        
         bool j1 = jump(stones,pos+k, k);
         bool j2 = jump(stones,pos+k+1, k+1);
         bool j3 = jump(stones,pos+k-1, k-1);
        
        string s1 = to_string(pos+k);
        s1.push_back(' ');
        s1.append(to_string(k));
            
        mp2[s1] = j1;
        
        string s2 = to_string(pos+k+1);
        s1.push_back(' ');
        s1.append(to_string(k+1));
            
        mp2[s2] = j2;
        
        string s3 = to_string(pos+k-1);
        s1.push_back(' ');
        s1.append(to_string(k-1));
            
        mp2[s3] = j3;
        
        
        
        return mp2[s] = j1 || j2 || j3;
    }
    bool canCross(vector<int>& stones) {
      if(stones[1]-stones[0]>1)
          return false;
      for(auto stone:stones)
      {
          mp[stone]==true;
      }
      return jump(stones,stones[1],1);   
    }
};