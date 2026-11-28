class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {
        long long steps = 0, water = capacity;
        for (int i = 0; i < (int)plants.size(); i++) {
            if (water >= plants[i]) {
                steps += 1;
            } else {
                steps += 2LL * i + 1;
                water = capacity;
            }
            water -= plants[i];
        }
        return (int)steps;
    }
};