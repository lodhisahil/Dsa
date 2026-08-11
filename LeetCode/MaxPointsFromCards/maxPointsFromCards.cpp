class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int l = 0;
        int r = 0;
        int arrSum = 0;
        int sum = 0;
        int maxSum = 0;
        for(int val : cardPoints){
            arrSum += val;
        }
        if(k == n){
            return arrSum;
        }
        while(r < n - k){
            sum += cardPoints[r];
            r++;
        }
        while(r < n){
            maxSum = max(maxSum, arrSum - sum);
            sum += cardPoints[r];
            sum -= cardPoints[l];
            r++;
            l++;
        }
        maxSum = max(maxSum, arrSum - sum);
        return maxSum;
    }
};