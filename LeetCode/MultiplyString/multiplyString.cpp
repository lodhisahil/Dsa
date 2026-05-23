class Solution {
public:

    string multiply(string num1, string num2) {

        int n1 = num1.length();
        int n2 = num2.length();

        vector<int> ans(n1 + n2, 0);

        for(int i = n1 - 1; i >= 0; i--){

            for(int j = n2 - 1; j >= 0; j--){

                int mul = (num1[i] - '0') * (num2[j] - '0');

                int sum = mul + ans[i + j + 1];

                ans[i + j + 1] = sum % 10;

                ans[i + j] += sum / 10;
            }
        }

        string result = "";

        for(int x : ans){

            if(!(result.empty() && x == 0)){
                result += (x + '0');
            }
        }

        return result.empty() ? "0" : result;
    }
};