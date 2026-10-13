class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        long long low = 1;
        long long high = 1LL * *min_element(ranks.begin(), ranks.end()) * cars * cars;
        long long ans = high;
        while (low <= high) {
            long long mid = low + (high - low) / 2;
            long long repaired = 0;
            for (int r : ranks) {
                repaired += sqrt((long double)mid / r);
                if (repaired >= cars) {
                    break;
                }
            }
            if (repaired >= cars) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};