#include<iostream>
using namespace std;

int main(){
//     int arr[]={1,2,3,4,5};
// int a=10;
// int* ptr=&a;
//     cout<<*arr<<endl;
//     cout<<*(arr+1)<<endl;
//     cout<<*(arr+2)<<endl;
//     cout<<*(arr+3)<<endl;
//     cout<<*(arr+4)<<endl;

     int arr[]={10,20,30,40};
  int *ptr = arr;
  cout<<*(ptr+1)<<endl;
  cout<<*(ptr+3)<<endl;
  ptr++ ;
  cout<<*ptr<<endl;
return 0;
}