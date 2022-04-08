

#include<bits/stdc++.h>
using namespace std;

void KSortedArray(vector<int> arr,int k){
    priority_queue<int,vector<int>, greater<int>> minh;
    int n = arr.size();
    for(int i=0;i<n;i++){
        minh.push(arr[i]);
        if(minh.size()>k){
            cout << minh.top() << " " ;
            minh.pop();
        }
    }
    while(minh.size()>0){
        cout << minh.top() << " " ;
        minh.pop();
    }
}



int main(){
    vector<int> arr = {6,5,3,2,8,10,9};
    KSortedArray(arr,3);
}