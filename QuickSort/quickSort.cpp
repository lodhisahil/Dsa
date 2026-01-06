#include<iostream>
#include<vector>
using namespace std;

int partition(vector<int> &arr, int st, int end){
    int i = st-1 , pivot = arr[end];
    for(int j=st; j<end; j++){
        if(arr[j] <= pivot){
            i++;
            swap(arr[j], arr[i]);
        }
    }
    i++;
    swap(arr[end], arr[i]);
    return i;

}

void quickSort(vector<int> &arr, int st, int end){
    if(st < end){
        int pivIdx = partition(arr, st, end);

        quickSort(arr, st, pivIdx-1);//left half
        quickSort(arr, pivIdx+1, end);//right half
    }
}

int main (){
    vector<int> arr = {5,94,54,50,89,6,17};

    quickSort(arr, 0, arr.size()-1);

    for(int val : arr){
        cout<<val<<" ";
    }
    cout<<endl;

    return 0;
}