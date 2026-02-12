#include<iostream>
#include<vector>
using namespace std ;

bool isValid(vector<int> &arr,int n , int m, int maxAllowedTime){
    int painters = 1;
    int time =0;
    for(int i=0;i<n;i++){
        if(time+arr[i]<=maxAllowedTime){
            time=time+arr[i];
        }
        else{
            painters++;
            time=arr[i];
        }
    }
    return painters<=m ? true : false ;
}

int minimumtime(vector<int> &arr,int n , int m){
    int sum=0 , maxval=arr[0];
    for(int i=0;i<n;i++){
        sum=sum+arr[i];
        maxval= max(maxval , arr[i]);
    }
    int st = maxval; 
    int end = sum ;
    int ans=-1;
    while(st<=end){
        int mid=st+(end-st)/2;
        if(isValid(arr, n , m ,mid)){
            ans = mid;
            end = mid-1;
        }
        else{
            st=mid+1;
        }
    }
    return ans;
}

int main(){
    vector<int> arr = {40,30,10,20};
    int n=4 ,m=2;

    cout<<minimumtime(arr, n ,  m);
    return 0;
}