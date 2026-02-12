#include  <iostream>
using namespace std;

void printhello(){
cout<<"Hello !!\n";
}

int sum(int a,int b){
    int sum = a+b ;
return sum;
}

int minof2(int a,int b){
    if(a>b){
        return b;
    } else{
        return a;
    }
}

int sumtoN(int n){
    int sum = 0;
    for(int i = 0 ; i<=n;i++ ){
        sum = sum + i ;
    }
    return sum ;
}

int factorialN(int n){
    int factorial = 1;
    for(int i=1 ; i<=n ;i++)
    factorial = factorial*i ;
    return factorial;
}

int sumofdigit(int n){
    int sum = 0;
    while( n>0 ){
        int remainder = n%10;
        sum=sum+remainder;
        n=n/10;
    }
    cout<<sum<<endl;
}

int ncr(int n, int r){
    int x = factorialN(n);
    int y = factorialN(r);
    int z = factorialN(n-r);
    int ncr = x/(y*z);

    return ncr ;
}

bool checkprime(int n){
    for(int i=2;i<=n;i++){
        if(n%i == 0 && i!=n){
            return false ;
        }
        else{
            return true ;
        }
    }
}

void printprime(int n){
    for(int i=1 ;i<=n ; i++){
        if(checkprime(i) == true ){
            cout<<i<<" " ;
        }
        
    }
}

void fibonacci(int n){
    int a = 0;
    int b = 1;
    int c ;
    int i=3;
    cout<<a<<" ";
    cout<<b<<" ";
    while(i<=n){
        c=a+b;
        cout<<c<<" ";
        a=b;
        b=c;
        i++ ;
    }
}

int main(){

 fibonacci(15);

return 0;
}