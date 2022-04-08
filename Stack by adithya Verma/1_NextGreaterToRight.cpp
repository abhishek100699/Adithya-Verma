/*Given an array find the nearest next grater element for each element in the array*/

#include<bits/stdc++.h>
using namespace std;

vector<int> NextGrater(vector<int> arr){
    vector<int> ans;
    stack<int> s;
    for(int i=arr.size()-1;i>=0;i--){
        if(s.empty()){
            ans.push_back(-1);
        }
        else{
            if(s.top()>arr[i]){
                ans.push_back(s.top());
            }
            else{
                while(s.top()<arr[i] && s.size()>0){
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
    reverse(ans.begin(),ans.end());
    return ans;
}

int main(){
    vector<int> arr = {1,3,2,4};
    cout << "The next grater elments are " ;
    vector<int> ans = NextGrater(arr);
    for(auto x:ans){
        cout << x << " " ;
    }

}