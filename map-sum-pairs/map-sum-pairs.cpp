class MapSum {
public:
    /** Initialize your data structure here. */
    MapSum() {}
    
    void insert(string key, int val) {
        m[key] = val;
    }
    
    int sum(string prefix) {
        int s = 0;
        for (auto [key, value] : m) if (key.find(prefix) == 0) s += value;
        return s;
    }
    
private:
    unordered_map<string, int> m;
};