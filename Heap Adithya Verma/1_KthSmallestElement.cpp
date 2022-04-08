// Given an unsorted array find the kth smallest element in the array

#include<bits/stdc++.h>
using namespace std;

int kthSmallestElement(vector<int> arr,int k){
    int n = arr.size();
    priority_queue<int> maxh;
    for(int i=0;i<n;i++){
        maxh.push(arr[i]);
        if(maxh.size()>k){
            maxh.pop();
        }
    }
    return maxh.top();
}

int main(){
    vector<int> arr = {7,10,4,3,20,15};
    cout << "The Kth smallest element is " << kthSmallestElement(arr,3) << endl;
}