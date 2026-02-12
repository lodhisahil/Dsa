#include <iostream>
#include <vector>
using namespace std;

int recursivebinsearch(vector<int> arr, int target , int st ,int end){
    if(st<=end){
        int mid=st+(end-st)/2;
        if (arr[mid] > target)
        {
          return  recursivebinsearch(arr,target,st,mid-1);   
        }
        else if (arr[mid] < target)
        {
            return  recursivebinsearch(arr,target,mid + 1,end);
        }
         else
        {
            return mid;
        }
    }
    return -1;
}

int binarysearch(vector<int> arr, int target)
{
    int end = arr.size() - 1;
    int st = 0;
    while (st <= end)
    {
        int mid = st+(end-st) / 2;
        if (arr[mid] > target)
        {
            end = mid - 1;
        }
        else if (arr[mid] < target)
        {
            st = mid + 1;
        }
        else
        {
            return mid;
        }
    }
    return -1;
}

int main()
{
   vector<int> arr1 = {-1,0,3,4,5,9,12};
   int tar1 = 20;
   
   vector<int> arr2 = {-1,0,3,5,9,12};
   int tar2 = 20;
   cout<<recursivebinsearch(arr1 , tar1 , 0 , 6)<<endl;
 

    return 0;
}