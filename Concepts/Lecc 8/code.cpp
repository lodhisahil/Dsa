#include <iostream>
using namespace std;

int smallest(int arr[], int size){


    int smallest = arr[0];
    int index;
    for (int i = 0; i < size; i++){
    if(arr[i]<smallest){
        smallest = arr[i];
    }
    }
    
    return smallest , index;
}
int smallestidx(int arr[], int size){


    int smallest = arr[0];
    int index;
    for (int i = 0; i < size; i++){
    if(arr[i]<smallest){
        smallest = arr[i];
    }
    }
    for (int i = 0; i < size; i++){
    if(arr[i]==smallest){
        index= i ;
    }
    }
    return index;
}



int largest(int arr[], int size){


    int largest = arr[0];
    for (int i = 0; i < size; i++){
    if(arr[i]>largest){
        largest = arr[i];
    }
    }
    return largest;
}


int largestidx(int arr[], int size){


    int largest = arr[0];
    int index ;
    for (int i = 0; i < size; i++){
    if(arr[i]>largest){
        largest = arr[i];
    }
    }
    for (int i = 0; i < size; i++){
    if(arr[i]==largest){
        index= i ;
    }
    }

    return index;
}

int linearsearch(int arr[] , int size , int target){

for(int i=0;i<size ; i++){
    if(target == arr[i]){
        return i ;
    }
}
return -1 ;
}

int main()
{

    int arr[6] = {5, 15, 22, 100, -15, 24};
    int ans = linearsearch(arr ,6 ,-25);
    cout<<ans<<endl;
    return 0;
}