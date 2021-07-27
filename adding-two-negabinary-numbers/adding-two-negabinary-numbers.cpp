class Solution {
public:
    #define pii pair<int,int>
    vector<int> addNegabinary(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int, pii> mp ;
        mp[-2] = {0,1}, mp[-1] = {1,1}, mp[0] = {0,0}, mp[1] = {1,0}, mp[2] = {0,-1}, mp[3] = {1,-1}; 
        vector<int> res ; 
        int n = arr1.size(), m = arr2.size();
        int i = n-1, j = m-1, carry = 0, currbit = 0; 
        while(i>= 0 || j >= 0 || carry){
            int currSum = carry; 
            if(i >=0 ) currSum += arr1[i--];
            if(j >= 0) currSum += arr2[j--]; 
            currbit = mp[currSum].first; 
            carry = mp[currSum].second; 
            res.push_back(currbit); 
        }
        reverse(res.begin(), res.end());
        auto it = res.begin(); 
        while(it!= res.end() && *it == 0) it ++; 
        if(it == res.end()) return {0}; 
        res = vector<int> (it, res.end()); 
        return res ; 
    }
};