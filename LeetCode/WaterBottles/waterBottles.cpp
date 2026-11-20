class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans = numBottles;
        int remBottles = ans;
        while(remBottles >= numExchange){
            int div = remBottles / numExchange;
            int rem = remBottles % numExchange;
            ans += div;
            remBottles = div + rem;
        }
        return ans;
    }
};