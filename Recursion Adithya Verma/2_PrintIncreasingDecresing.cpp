#include<bits/stdc++.h>
using namespace std;

void printIncreasingDecresing(int n){
    if(n==0){
        return;
    }
    cout << n << " " ;
    printIncreasingDecresing(n-1);
    cout << n << " " ;
}


int main(){
    printIncreasingDecresing(4);
}