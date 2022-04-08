/*Given an array of numbers print the top k frequent numbers in the array*/

#include<bits/stdc++.h>
using namespace std;

void TopKFrequent(vector<int> arr, int k){
    unordered_map<int,int> m;
    for(auto x: arr){
        m[x]++;
    }
    priority_queue< pair<int,int>, vector<pair<int,int>> ,greater<pair<int,int>>> minh;
    for(auto x:m){
        minh.push({x.second,x.first});
        if(minh.size() > k){
            minh.pop();
        }
    }
    cout << "top K Frequent numbers are " << endl;

    while(minh.size()>0){
        cout << minh.top().second << " " ;
        minh.pop();
    }

}


int main(){

    vector<int> arr = {1,1,1,3,2,2,4};
    TopKFrequent(arr,2);
    
}