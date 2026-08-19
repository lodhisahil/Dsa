// class Solution {
// public:
//     int candy(vector<int>& ratings) {
//         int n = ratings.size();
//         vector<int> left(n , 1);
//         vector<int> right(n , 1);
//         for(int i = 1; i < n; i++){
//             // i = i
//             int j = n - 1 - i;
//             if(ratings[i] > ratings[i-1]){
//                 left[i] = left[i-1] + 1;
//             }else{
//                 left[i] = 1;
//             }
//             if(ratings[j] > ratings[j+1]){
//                 right[j] = right[j+1] + 1;
//             }else{
//                 right[j] = 1;
//             }
//         }
//         int i = 0;
//         int sum = 0;
//         while(i < n){
//             sum += max(left[i], right[i]);
//             i++;
//         }
//         return sum;
//     }
// };
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        int sum = 1;
        int i = 1;
        while(i < n){
            if(ratings[i] == ratings[i-1]){
                sum += 1;
                i++;
                continue;
            }
            int peak = 1;
            while(i < n && ratings[i] > ratings[i-1]){
                peak++;
                sum += peak;
                i++;
            }
            int down = 1;
            while(i < n && ratings[i] < ratings[i-1]){
                sum += down;
                down++;
                i++;
            }
            if(down > peak){
                sum += down - peak;
            }
        }
        return sum;
    }
};