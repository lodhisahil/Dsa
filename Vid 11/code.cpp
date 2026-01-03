#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n =7 ;
    int arr[7]={3,-4,5,4,-1,7,-8};

    // for (int st=0;st<n;st++){
    //     for (int end =st ; end<n;end++){
    //         for(int i=st;i<=end;i++){
    //             cout<<arr[i]<<" ";
    //         } 
    //         cout<<"    ";
    //     }
    //     cout<<endl;
    // }

//     int maxsum = INT16_MIN;
//   for (int st=0;st<n;st++){
//     int currsum = 0;
//         for (int end =st ; end<n;end++){
//            currsum = currsum + arr[end];
//            maxsum = max(currsum , maxsum);
//         }
//         cout<<endl;
//     }

//     cout<<maxsum<<endl;

// Kadanes algorithm
int currsum = 0;
int maxsum = INT16_MIN ;
for(int i=0;i<n;i++){
    currsum = currsum + arr[i];
    maxsum = max(currsum , maxsum);
    if(currsum<0){
        currsum=0;
    }
}
cout<<maxsum<<endl;
    return 0;
}
