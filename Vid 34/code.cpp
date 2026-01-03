#include <iostream>
#include <vector>
using namespace std;

int countDigits(int n)
{
    int count = 0;
    while (n != 0)
    {
        count++;
        n /= 10;
    }
    return count;
}

bool toCheckArmnum(int n)
{
    int sum = 0;
    int copyN = n;
    while (n != 0)
    {
        int digit = n % 10;
        sum = sum + (digit * digit * digit);
        n /= 10;
    }
    return sum == copyN;
}

int findGCD(int a, int b)
{
    for (int i = min(a, b); i > 0; i--)
    {
        if (a % i == 0 && b % i == 0)
        {
            return i;
        }
    }
    return -1;
}

int gcd(int a, int b)
{
    while (a > 0 && b > 0)
    {
        if (a > b)
        {
            a %= b;
        }
        else
        {
            b %= a;
        }
    }
    if (a == 0)
        return b;
    return a;
}

int lcm(int a, int b)
{
    int gcd1 = gcd(a, b);
    int lcm = (a * b) / gcd1;
    return lcm;
}

int reverseNum(int n)
{
    int reverse = 0;
    while (n > 0)
    {
        if (reverse > INT_MAX / 10 || reverse < INT_MIN / 10)
        {
            return 0;
        }
        reverse = reverse * 10 + (n % 10);
        n = n / 10;
    }
    return reverse;
}

bool toCheckPalindrome(int n)
{
    if (n == reverseNum(n))
    {
        return true;
    }
    return false;
}

int main()
{

    cout << toCheckPalindrome(1261) << endl;

    return 0;
}