#include<bits/stdc++.h>
using namespace std;


void display(int arr[],int indx,int n){
    if(indx == n) return;
    cout << arr[indx] << " " ;
    display(arr, indx+1,n);
}


void displayReverse(int arr[], int indx){
    if(indx==0){
        return ;
    }
    cout << arr[indx-1] << " ";
    displayReverse(arr,indx-1);
}


int main(){
    int arr[] = {1,2,3,4,5,6};
    cout << "Forword :  " ;
    display(arr,0,6);
    cout << endl;
    cout << "Reverse : " ;
    displayReverse(arr,6);
}