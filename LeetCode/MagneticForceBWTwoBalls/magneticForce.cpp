class Solution {
public:

    bool possible(vector<int>& position, int mid, int m){
        int lastBall = position[0];
        int balls = 1;
        for(int i=1; i<position.size(); i++){
            if(position[i] - lastBall >= mid){
                balls++;
                lastBall = position[i];
            }
        }
        if(balls >= m){
            return true;
        }
        return false;
    }

    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int n = position.size();
        int st = 1;
        int end = position[n-1] - position[0];
        while(st <= end){
            int mid = st + (end - st)/2;
            if(possible(position, mid, m)){
                st = mid + 1;
            }else {
                end = mid - 1;
            }
        }
        return end;
    }
};