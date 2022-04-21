#include<bits/stdc++.h>
using namespace std;


void TOH(int n,char t1,char t2, char t3){
    if(n==0) return;
    TOH(n-1,t1, t3, t2);
    cout << n << " " << t1 << "-> " << t2 << endl;
    TOH(n-1,t3,t2,t1); 
}

int main(){
    TOH(3,'A','B','C');
}