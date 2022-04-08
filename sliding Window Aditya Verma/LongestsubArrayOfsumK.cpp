// find the longest Subarray with sum k
#include<bits/stdc++.h>
using namespace std;

int longestSubarray(int *arr,int n,int k){
    int i=0,j=0;
    int sum = 0;
    int maxlen = INT_MIN;
    while(j<n){
        
        sum = sum + arr[j];
        

        if(sum > k){
            while(sum>k){
                sum = sum - arr[i];
                i++;
            }
        }

        else if(sum == k){
            maxlen = max(maxlen,j-i+1);
            j++;
        }
    }
    return maxlen;
}


int main(){
    int arr[] = {-5,8,-14,2,4,12};
    int k = -5;
    cout << "Maximum window size is " << longestSubarray(arr,6,k);

}