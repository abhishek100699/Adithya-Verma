#include<bits/stdc++.h>
using namespace std;

vector<int> NearestSmaller(vector<int> arr){
    vector<int> v;
    stack<int> s;
    for(int i=0;i<arr.size();i++){
        if(s.size() == 0){
            v.push_back(-1);
        }
        else{
            if(s.top() < arr[i]){
                v.push_back(s.top());
            }
            else{
                while(s.top()>arr[i] && s.size()>0){
                    s.pop();
                }
                if(s.size()==0) v.push_back(-1);
                else v.push_back(s.top());
            }
        }
        s.push(arr[i]);
    }
    return v;
}



int main(){
    vector<int> arr = {4,5,2,10,8};
    vector<int> ans = NearestSmaller(arr);
    cout << "Nearest Smaller element to left is : " ;
    for(auto x:ans){
        cout << x << " " ;
    }
}