class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        long long totalMass = mass;
        sort(asteroids.begin(), asteroids.end());
        int n = asteroids.size();
        for(int stone : asteroids){
            if(totalMass < stone){
                return false;
            }else{
                totalMass += stone;
            }
        }
        return true;
    }
};