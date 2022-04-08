#include<bits/stdc++.h>
using namespace std;

int MinCost(vector<int> arr){
    int n = arr.size();
    priority_queue<int, vector<int>, greater<int>> minh;
    for(auto x:arr) minh.push(x);
    int ans = 0;
    while(minh.size()>=2){
        int a = minh.top();
        minh.pop();
        int b = minh.top();
        minh.pop();
        ans = ans + (a+b);
        minh.push(a+b);
        if(minh.size()==1) break;
    }
    return ans;
}


int main(){
    vector<int> arr = {1,2,3,4,5};
    cout << "Min cost of the rope is " << MinCost(arr);
}