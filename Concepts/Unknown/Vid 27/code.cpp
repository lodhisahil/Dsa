#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <stack>
#include <queue>
#include <map>
#include <unordered_map>
using namespace std;

int main()
{
    // vector<pair<int , int >> vec = {{1,2} , {2,3} , {3,4}};
    // vec.push_back({4,5});
    // vec.emplace_back(5,6);
    //     for(auto p : vec){
    //         cout<<p.first<<" "<<p.second<<endl;
    //     }

    // stack<int> s ;
    // s.push(11);
    // s.push(12);
    // s.push(13);
    // s.emplace(14);
    // cout<<s.size()<<endl;
    // while(!s.empty()){
    //     cout<<s.top()<<" "<<endl;
    //     s.pop();
    // }
    // cout<<s.size()<<endl;

    // queue<int> q ;
    // q.push(11);
    // q.push(12);
    // q.push(13);
    // q.emplace(14);
    // cout<<q.size()<<endl;
    // while(!q.empty()){
    //     cout<<q.front()<<" "<<endl;
    //     q.pop();
    // }
    // cout<<q.size()<<endl;

    // priority_queue<int> q ;
    // priority_queue<int, vector<int>, greater<int>> q; // to reverse the order of elements
    // q.push(5);
    // q.push(3);
    // q.push(10);
    // q.emplace(4);
    // cout << q.size() << endl;
    // while (!q.empty())
    // {
    //     cout << q.top() << " ";
    //     q.pop();
    // }
    // cout << endl;
    // cout << q.size() << endl;

    //     map<string , int> m;
    //     m["Tv"] = 100 ;
    //     m["Laptop"] = 100 ;
    //     m["Headphones"] = 50 ;
    //     m["Tablet"] = 50 ;
    //     m["Watch"] = 50 ;
    //     m.insert({"Camera" , 500});
    //     m.emplace("Kamera" , 500);
    //     m.erase("Tv");
    // for( auto p:m){
    //     cout<<p.first<<" "<<p.second<<endl;
    // }

    // multimap<string , int> m;
    // m.insert({"Camera" , 500});
    // m.emplace("Kamera" , 500);
    // m.emplace("Kamera" , 500);
    // m.emplace("Kamera" , 500);
    // m.emplace("Kamera" , 500);
    // m.erase(m.find("Kamera"));
    // for( auto p:m){
    // cout<<p.first<<" "<<p.second<<endl;
    // }

    // unordered_map<string , int> m;
    // m.insert({"Camera" , 500});
    // m.emplace("laptop" , 500);
    // m.emplace("fridge" , 500);
    // m.emplace("watch" , 500);

    // for( auto p:m){
    // cout<<p.first<<" "<<p.second<<endl;
    // }

    return 0;
}