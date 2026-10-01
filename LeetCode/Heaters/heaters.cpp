class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(heaters.begin(), heaters.end());
        int ans = 0;
        for (int house : houses) {
            int idx = lower_bound(heaters.begin(), heaters.end(), house) - heaters.begin();
            int left = INT_MAX;
            int right = INT_MAX;
            // Heater on the right
            if (idx < heaters.size()) {
                right = heaters[idx] - house;
            }
            // Heater on the left
            if (idx > 0) {
                left = house - heaters[idx - 1];
            }
            int nearest = min(left, right);
            ans = max(ans, nearest);
        }
        return ans;
    }
};