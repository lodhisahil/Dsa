#include <iostream>
#include <vector>
using namespace std;

void bubblesort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        bool isSwap = false;
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                isSwap = true;
            }
        }
        if (!isSwap)
        {
            return;
        }
    }
}

void selectionsort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int smallest = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[smallest])
            {
                smallest = j;
            }
        }
        swap(arr[smallest], arr[i]);
    }
}


void insertionsort(int arr[], int n)
{
    for (int i = 1; i < n; i++){
        int curr = arr[i];
        int prev = i-1 ;
        while(prev >=0 && arr[prev] > curr){
            arr[prev+1] = arr[prev] ;
            prev -- ;
        }
        arr[prev+1] = curr ;
    }
}


void printarray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr[5] = {4, 1, 5, 2, 3};
    int n = 5;

    insertionsort(arr, n);
    printarray(arr, n);

    return 0;
}