class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maxi = 0;
        for(int candy : candies){
            maxi = max(maxi, candy);
        }
        vector<bool> ans;
        for(int candy : candies){
            if(candy + extraCandies >= maxi){
                ans.push_back(true);
            }else{
                ans.push_back(false);
            }
        }
        return ans;
    }
};