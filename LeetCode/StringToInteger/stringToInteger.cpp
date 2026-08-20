//normal approach
class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        int sign = 1;
        while(s[i] == ' ' && i<s.length()){
            i++;
        }
        if(s[i] == '-'){

            sign = -1;
            i++;
            if(i < s.length() && !isdigit(s[i])){
                return 0;
            }
        }
        if(s[i] == '+'){
            i++;
        }
        long long num = 0;
        while(i<s.length() && isdigit(s[i])){
            int digit = s[i] - '0';
            //check for overflow
            if(num > (INT_MAX - digit) / 10){
                if(sign == -1){
                    return INT_MIN;
                }else{
                    return INT_MAX;
                }
            }
            num = num * 10 + digit;
            i++;
        }
        return num * sign;
    }
};
