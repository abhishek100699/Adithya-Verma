// find the first negative number in every window of size k


#include<bits/stdc++.h>
using namespace std;

vector<int> firstNegative(int *arr,int n,int k){
    vector<int> ans;
    list<int> l;
    int i=0,j=0;
    while(j<n){
        if(arr[j] <0 ){
            l.push_back(arr[j]);
        }
        if(j-i+1 < k){
            j++;
        }
        else if(j-i+1 == k){
            if(l.size()==0){
                ans.push_back(0);
            }
            else{
                ans.push_back(l.front());
                if(arr[i] < 0){
                    l.pop_front();
                }
            }
            i++;
            j++;
        }
    }
   return ans;
}



int main(){

    int arr[] = {12,-1,-7,8,-16,30,13,28};
    vector<int> final = firstNegative(arr,8,3);
    cout << "The final list is : " << endl;
    for(auto x: final){
        cout << x << " " ;
    }

}