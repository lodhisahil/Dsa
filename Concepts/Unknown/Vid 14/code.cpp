#include<iostream>
#include<vector>
using namespace std;

int linearsearch(int arr[] , int size , int target){
    for(int i=0;i<size;i++){
        if(arr[i]==target){
            return i ;
        }
    }
}

int smallest(int arr[] , int size){
    int min = arr[0];
    int i ;
    for(i=0;i<size;i++){
        if(arr[i]<min){
            min=arr[i];
        }
    }
    return min;
}

int biggest(int arr[] , int size){
    int big = arr[0];
    int i ;
    for(i=0;i<size;i++){
        if(arr[i]>big){
            big=arr[i];
        }
    }
    return big;
}

int main(){
int arr[6]={7,1,5,3,6,4};
int min = smallest(arr,6);
int minIdx = linearsearch(arr , 6 ,  min);

int big = arr[minIdx];
    int i ;
    for(i=minIdx;i<6;i++){
        if(arr[i]>big){
            big=arr[i];
        }
    }

int bigIdx = linearsearch(arr , 6 ,  big);

cout<<"Best day to buy a stock:"<<min <<endl;
cout<<"Best day to sell a stock:"<<big <<endl;
cout<<"Max profit :"<<arr[bigIdx]-arr[minIdx]<<endl;
    return 0;
}