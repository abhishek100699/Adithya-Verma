#include<bits/stdc++.h>
using namespace std;

int  maxOfArray(int arr[],int indx,int n){
    if(indx == n-1) return arr[indx];
    int ans = maxOfArray(arr,indx+1,n-1);
    return max(ans, arr[indx]);
}


int main(){
    int arr[] = {4,3,5,2,1};
    cout << maxOfArray(arr,0, 5);
}