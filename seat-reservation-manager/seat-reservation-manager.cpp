class SeatManager {
public:
    set<int> s1;
    SeatManager(int n) {
        for(int i=1;i<=n;i++)
            s1.insert(i);
    }
    
    int reserve() {
        auto it = s1.begin();
        int ans = *it;
        s1.erase(it);
        return ans;
    }
    
    void unreserve(int seatNumber) {
        s1.insert(seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */