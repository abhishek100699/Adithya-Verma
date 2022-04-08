// Longest SubString with K unique Charcter

#include<bits/stdc++.h>
using namespace std;

int longestSubString(string str,int k){
    int i=0,j=0;
    map<char,int> mp;
    int n = str.length();
    int count = 0;
    int maxi = INT_MIN;
    while(j<n){
        mp[str[j]]++;
        count++;
        if(mp.size() == k){
            maxi = max(maxi,count);
        }
        if(mp.size() > k){
            while(mp.size() > k){
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
    return count;
}


int main(){
    string str = "aabaaadcbeeaaaeb";
    int k = 3;
    cout << "The longestSubString is " << longestSubString(str,3);
}