#include<bits/stdc++.h>
using namespace std;

int pow(int x,int n){
    if(n==0) return 1;
    int xn = pow(x,n/2);
    int ans = xn*xn;
    if(n%2==1){
        ans = ans*x;
    }
    return ans;
}


int main(){
    cout << pow(2,10) << endl;
}