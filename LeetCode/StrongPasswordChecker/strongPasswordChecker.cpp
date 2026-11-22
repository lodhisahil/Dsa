class Solution {
public:
    int strongPasswordChecker(string password) {
        int n = password.size();

        bool hasLower = false, hasUpper = false, hasDigit = false;
        for (char c : password) {
            if (islower(c)) hasLower = true;
            else if (isupper(c)) hasUpper = true;
            else if (isdigit(c)) hasDigit = true;
        }
        int missing = (!hasLower) + (!hasUpper) + (!hasDigit);

        // replace = total replacements to break all runs >= 3
        // one = runs with L%3==0, two = runs with L%3==1
        int replace = 0, one = 0, two = 0;
        for (int i = 2; i < n;) {
            if (password[i] == password[i - 1] && password[i] == password[i - 2]) {
                int len = 2;
                while (i < n && password[i] == password[i - 1]) {
                    len++;
                    i++;
                }
                replace += len / 3;
                if (len % 3 == 0) one++;
                else if (len % 3 == 1) two++;
            } else {
                i++;
            }
        }

        if (n < 6) return max(6 - n, missing);
        if (n <= 20) return max(replace, missing);

        int del = n - 20;

        // 1 delete per saved replacement (L%3==0)
        replace -= min(del, one);
        // 2 deletes per saved replacement (L%3==1)
        replace -= min(max(del - one, 0), two * 2) / 2;
        // 3 deletes per saved replacement (remaining)
        replace -= max(del - one - 2 * two, 0) / 3;

        return del + max(missing, replace);
    }
};