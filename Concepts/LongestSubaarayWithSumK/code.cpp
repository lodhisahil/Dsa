#include<bits/stdc++.h>
using namespace std;

int longestSumK(vector<int> &arr, int k){
    /*
    int length = 0;
    unordered_map<int, int> mpp;
    int sum = 0;
    for(int i=0; i<arr.size(); i++){
        sum += arr[i];
        if(sum == k){
            length = max(length, i+1);
        }
        int rem = sum - k;
        if(mpp.find(rem) != mpp.end()){
            length = max(length, i - mpp[rem]);
        }
        if(mpp.find(sum) == mpp.end()){
            mpp[sum] = i;
        }
    }
    return length;
    */
    int l = 0;
    int r = 0;
    int sum = 0;
    int length = 0;
    while(r < arr.size()){
        sum += arr[r];
        while(sum > k){
            sum -= arr[l];
            l++;
        }
        if(sum == k){
            length = max(length, r - l + 1);
        }
        r++;
    }
    return length;
}

int main(){
    // vector<int> arr = {1, 2, 3, 1, 1, 1, 1};
    // vector<int> arr = {1, 2, 3, 1, 0, 1, 1, 1};
    vector<int> arr = {2, 0, 0, 3};
    cout<<longestSumK(arr, 3);
    return 0;
}