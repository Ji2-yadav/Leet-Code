class Solution {
public:
    int maxArea(int h, int w, vector<int>& hc, vector<int>& vc) {
       sort(hc.begin(), hc.end()); hc.push_back(h); // adding the height to get that difference at the end
        sort(vc.begin(), vc.end()); vc.push_back(w); // same for width
        adjacent_difference(hc.begin(), hc.end(), hc.begin());
        adjacent_difference(vc.begin(), vc.end(), vc.begin());
        return (static_cast<long>(*max_element(hc.begin(), hc.end())) * *max_element(vc.begin(), vc.end())) % 1000000007;
            

    }
};