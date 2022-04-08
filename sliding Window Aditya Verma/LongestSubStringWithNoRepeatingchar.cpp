// Longest Substring With No Repeating Character (all unique char)

#include<bits/stdc++.h>
using namespace std;

int longestNonrepeating(string str){
    int i=0,j=0;
    map<char,int> mp;
    int count = 0;
    int n = str.length();
    int maxi = -1;
    while(j<n){
        mp[str[j]]++;
        if(mp.size() == j-i+1)
            maxi = max(maxi,j-i+1),j++;
        
        // condition for the repeating elements
        else if(mp.size() < j-i+1){
            while(mp.size()<j-i+1){
                mp[str[i]]--;
                if(mp[str[i]] == 0)
                    mp.erase(str[i]);
                   
                i++;
            }
            j++;
        }
       
    }
    return maxi;
}


int main(){
    string str = "eeydgwdykpv";
    cout << "Maximum window size : " << longestNonrepeating(str);
}