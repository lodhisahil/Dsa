#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool isPalindrome(string str, int n){
    int st = 0 , end = str.length()-1 ;
    while(st<end){
        if(tolower(str[st]) != tolower(str[end])){
            return false;
        }
        st++ , end-- ;
    }
    return true;
}

int main() {

string str1 = "Racecar" ;
string str2 = "sahil" ;

cout<<isPalindrome(str1, 7)<<endl;
cout<<isPalindrome(str2, 5)<<endl;

    return 0;
}