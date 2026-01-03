#include <iostream>
#include <vector>
using namespace std;

int linearsearch(vector<int> vec , int target ){
    for(int i =0 ;i<vec.size() ;i++){
        if(vec[i]==target){
            return i;
        }
    }

}

void reversearray(vector<int>& vec){
    int start = 0;
    int end =vec.size()-1;
    while(start<end){
        swap(vec[start] , vec[end]);
        start++;
        end--;

    }
}

int main(){

    vector<int> vec ={1,2,3,45,5,6,7,8,9} ;
   
reversearray(vec);
for(int val : vec){
    cout<<val<<" ";
}

    return 0;             
}
