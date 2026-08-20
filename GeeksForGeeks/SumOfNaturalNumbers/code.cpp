#include <iostream>
using namespace std;

int summ(int n, int sum){
    if(n < 1){
        return sum;
    }
    sum += n;
    return summ(n-1, sum);
}

int main() {
    int n;
    cin >> n;

    // code here
    cout<<summ(n, 0);
    

    return 0;
}