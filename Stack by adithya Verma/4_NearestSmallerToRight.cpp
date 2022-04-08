#include<bits/stdc++.h>
using namespace std;


vector<int> nearestSmallerFromRight(vector<int> v){
    vector <int> ans;
    stack<int> s;
    int n=v.size();
    for(int i=n-1;i>=0;i--){
        if(s.size()>0 && s.top()>=v[i]){
            while(s.size()>0 && s.top()>=v[i]){
                s.pop();
            }
        }
        if(s.size()==0){
            ans.push_back(-1);
        }
        else{
            ans.push_back(s.top());
        }
        s.push(v[i]);
    }
    reverse(ans.begin(),ans.end());
    return ans;
}


int main(){
    vector<int> arr = {4,5,2,10,8};
    vector<int> ans = nearestSmallerFromRight(arr);
    cout << "Nearest Smaller to right is : " ;
    for(auto x:ans){
        cout << x << " " ;
    }
}