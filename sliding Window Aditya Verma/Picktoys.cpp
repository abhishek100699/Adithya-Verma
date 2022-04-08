/*
Given a String which represents the type of toys
1. you have to  pick toys in continuous manner
2. only two type of toys can be taken
*/

#include<bits/stdc++.h>
using namespace std;


int pickToys(string str,int k){
    k = 2;
    int i=0,j=0,count=0,maxi = INT_MIN;
    int n = str.length();
    map<char,int> mp;
    while(j<n){
        mp[str[j]]++;
        count++;
        if(mp.size() == k){
            maxi = max(count,maxi);

        }
        if(mp.size()>k){
            while(mp.size()>k){
                mp[str[i]]--;
                count--;
                if(mp[str[i]] == 0){
                    mp.erase(str[i]);
                }
                i++;
            }
        }
        j++;
    }
    return maxi;
}


int main(){
    string str = "abaccab";
    int k = 2;
    cout << "Maximum size Substring is " << pickToys(str,k) << endl;
}