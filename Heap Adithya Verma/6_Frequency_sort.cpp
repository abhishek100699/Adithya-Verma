/*Frequency Sort*/

#include<bits/stdc++.h>
using namespace std;

void FrequencySort(vector<int> arr){
    unordered_map<int,int> mp;
    for(auto x: arr){
        mp[x]++;
    }
    priority_queue<pair<int,int>> maxh;
    for(auto x:mp){
        maxh.push({x.second,x.first});
    }

    while(maxh.size()>0){
        int first = maxh.top().first;
        int second = maxh.top().second;
        while(first--){
            cout << second << " ";
        }
        maxh.pop();
    }

}



int main(){
    vector<int> arr = {1,1,1,3,2,2,4};
    FrequencySort(arr);

}