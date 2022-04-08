// given an unsorted array find the first k larget elements

#include<bits/stdc++.h>
using namespace std;


void kLargestElements(vector<int> arr, int k){
    priority_queue<int,vector<int>,greater<int>> minh;
    int n = arr.size();
    for(int i=0;i<n;i++){
        minh.push(arr[i]);
        if(minh.size() > k){
            minh.pop();
        }
    }
    cout << "First K Larget Elements are " ;
    while(minh.size()>0){
        cout << minh.top() << " " ;
        minh.pop();
    }
}

int main(){
    vector<int> arr = {7,10,4,3,20,15};
    kLargestElements(arr,3);
}