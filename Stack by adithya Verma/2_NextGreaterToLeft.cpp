/*Given an array find the first  grater element to left of every element in the array */
#include<bits/stdc++.h>
using namespace std;

vector<int> LeftGraterElement(vector<int> arr){
    vector<int> ans;
    stack<int> s;
    for(int i=0;i<arr.size();i++){
        if(s.size()==0){
            ans.push_back(-1);
        }
        else{
            if(s.top()>arr[i]){
                ans.push_back(s.top());
            }
            else{
                while(s.top()<=arr[i] && s.size()>0){
                    s.pop();
                }
                if(s.empty()){
                    ans.push_back(-1);
                }
                else{
                    ans.push_back(s.top());
                }
            }
        }
        s.push(arr[i]);
    }
    return ans;
}


int main(){
    vector<int> arr = {1,3,2,4};
    vector<int> v = LeftGraterElement(arr);
    cout << "the Left greater element to left is " ;
    for(auto x: v){
        cout << x << " " ;
    }
}

