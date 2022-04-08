/*given an array of numbers find the k closest number for the given x*/

#include<bits/stdc++.h>
using namespace std;


void kclosest(int arr[],int n,int k,int x){
    priority_queue<pair<int,int>> maxh;
    for(int i=0;i<n;i++){
        maxh.push({abs(arr[i]-x),arr[i]});
        if(maxh.size()>k){
            maxh.pop();
        }
    }
    cout << "K closest Numbers are : " << endl;
    while(maxh.size()>0){
        cout << maxh.top().second << " " ;
        maxh.pop();
    }
}

int main(){
    int arr[] = {5,6,7,8,9};
    kclosest(arr,5,3,7);
}