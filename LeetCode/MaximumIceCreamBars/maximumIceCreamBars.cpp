class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int count[100001] = {};
        for(int cost : costs) {
            count[cost]++;
        }
        int ans = 0;
        for(int price = 1; price <= 100000; price++) {
            while(count[price] > 0 && coins >= price) {
                coins -= price;
                ans++;
                count[price]--;
            }
            if(coins < price) {
                break;
            }
        }
        return ans;
    }
};