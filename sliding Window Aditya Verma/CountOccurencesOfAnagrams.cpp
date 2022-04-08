// Count the Occurence of the anagram the the fiven pattern in the string 

#include<bits/stdc++.h>
using namespace std;


int countOccurences(string str,string pat){
    int ans = 0;
    vector<int> hash(26,0);
    vector<int> phash(26,0);
    int k = pat.length();
    int n = str.length();
    int i=0,j=0;

    // for the fisrt window
    while(j<k){
        phash[pat[j] - 'a']++;
        hash[str[j++] - 'a']++;
    }

    j--;
    // For Rest Of the windows
    while(j<n){
        if(phash == hash){
            ans++;
        }
        j++;
        if(j!=n){
            hash[str[j] - 'a']++;
        }
        hash[str[i]-'a']--;
        i++;
    }
    return ans;
}



int main(){
    string str ;
    cout << "Enter the Source String " << endl;
    cin >> str;
    string pat ;
    cout << "Enter the pattern String " << endl;
    cin >> pat;

    cout << "Total Number of occurence of the pattern : " << countOccurences(str,pat);
}