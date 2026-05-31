class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> array;
        long long ans = 1;
        array.push_back(1);
        for(int i=1; i<rowIndex + 1; i++){
            ans = ans * (rowIndex + 1 - i);
            ans = ans / i;
            array.push_back((int)ans);
        }
        return array;
    }
};