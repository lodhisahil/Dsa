class Solution {
  public:
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        vector<pair<double,pair<int, int>>> items;
        for(int i=0; i<wt.size(); i++){
            double ratio = (double)val[i] / wt[i];
            items.push_back({ratio, {val[i], wt[i]}});
        }
        sort(items.rbegin(), items.rend());
        
        double ans = 0;
        for(int i=0; i<items.size(); i++){
            int value = items[i].second.first;
            int weight = items[i].second.second;
            if(capacity >= weight){
                ans += value;
                capacity -= weight;
            }else{
                ans += items[i].first * capacity;
                break;
            }
        }
        return ans;
    }
};