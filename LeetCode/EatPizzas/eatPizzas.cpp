class Solution {
public:
    long long maxWeight(vector<int>& pizzas) {
        sort(pizzas.begin(), pizzas.end());
        int n = pizzas.size();
        int days = n / 4;
        int oddDays = (days + 1) / 2;
        int evenDays = days / 2;
        long long ans = 0;
        int i = n - 1;
        while (oddDays--) {
            ans += pizzas[i];
            i--;
        }
        while (evenDays--) {
            i--;
            ans += pizzas[i];
            i--;
        }
        return ans;
    }
};