/*Given an array find the nearest next grater element for each element in the array*/

#include<bits/stdc++.h>
using namespace std;

vector<int> NextGrater(vector<int> arr){
    
    int n = arr.size();
    vector<int> ans;                                   
    stack<int> s;
    for(int i=n-1;i>=0;i--){
        if(s.empty()){
            ans.push_back(-1);
        }
        else{
            if(s.top()>arr[i]){
                ans.push_back(s.top());
            }
            else {
                // Very Very Imp 
                // first check the condition if there is empty stack or not

                while(!s.empty() && s.top()<=arr[i]){
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
   //vector<int> arr = {1,3,2,4};
   vector<int> arr = {73,74,75,71,69,72,76,73};
    cout << "The next grater elments are " ;
    vector<int> ans = NextGrater(arr);
    for(auto x:ans){
        cout << x << " " ;
    }

}