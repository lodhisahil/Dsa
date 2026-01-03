#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

bool isPossible(vector<int> &arr , int n, int m ,int minAllowedDist){
    int cows = 1;
    int lastStallPos = arr[0];
    for(int i=1;i<n ; i++){
        if((arr[i]-lastStallPos)>=minAllowedDist){
            cows++;
            lastStallPos= arr[i];
        }
        if(cows==m){
            return true;
        }
    }
    return false;
}

int maxdistance(vector<int> &arr , int n, int m){
    sort(arr.begin(), arr.end());
    int st=1 ;
    int maxval = arr[0] , minval=arr[0] ;
    for(int i=0;i<n;i++){
        maxval = max(maxval , arr[i]);
        minval = min(minval , arr[i]);
    }
    int end = (maxval-minval);
    int ans=-1;
    while(st<=end){
        int mid= st+(end-st)/2;
        if(isPossible(arr , n ,m ,mid)){
            ans=mid;

            st=mid+1;
        }
        else{
            end=mid-1;
        }
    }
    return ans;
}

int main(){
    vector<int> arr={1,2,8,4,9};
    int n=5 ,m=3;

    cout<<maxdistance(arr , n, m);
    return 0;
}