#include<iostream>
using namespace std;

int dectobin(int n){
    int ans = 0;
    int rem ;
    int mul = 1;
    while(n>0){
        rem = n%2 ;
        n = n/2 ;
        ans = ans+(rem* mul) ;
        mul=mul*10 ;
    }
    return ans ;
}

int bintodec(int n){
int ans = 0 ;
int rem ;
int mul = 1;
while(n>0){
    rem=n%10;
    ans = ans + (rem*mul);
    n = n/10;
    mul = mul*2;
    }
    return ans;
}


int main(){  
    cout<<dectobin(37)<<endl;
    cout<<dectobin(41)<<endl;
    cout<<dectobin(19)<<endl;
    return 0;
} 