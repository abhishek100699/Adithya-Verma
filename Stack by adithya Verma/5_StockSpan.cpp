#include<bits/stdc++.h>
using namespace std;


vector<int> StockSpan(vector<int> arr){
    vector<int> v;
    stack<pair<int ,int>> s;
    for(int i=0;i<arr.size();i++){
        if(s.size()==0){
            v.push_back(-1);
        }
        else{
            if(s.top().first>arr[i]){
                v.push_back(s.top().second);
            }
            else{
                while(s.top().first <= arr[i] && s.size()>0){
                    s.pop();
                }
                if(s.size()==0){
                    v.push_back(-1);
                }
                else{
                    v.push_back(s.top().second);
                }
            }
        }
        s.push({arr[i],i});
    }

    for(int i=0;i<arr.size();i++){
        v[i] = i-v[i];
    }
    return v;
    
}


int main(){

    vector<int> arr = {100,80,60,70,60,75,85};
    vector<int> ans = StockSpan(arr);
    for(auto x:ans){
        cout << x << " " ;
    }
}