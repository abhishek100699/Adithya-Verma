// find the maximum Size Subarray with size k

#include<bits/stdc++.h>
using namespace std;

int maxSumSubArray(int *arr,int n,int k){
    int i=0,j=0;
    int maxsum = INT_MIN;
    int sum = 0;
    while(j<n){
        sum = sum +arr[j];
        if(j-i+1 < k){
            j++;
        }

        else if(j-i+1 == k){
            maxsum = max(maxsum,sum);
            sum = sum -arr[i];
            i++;
            j++;
        }
    }
    return maxsum;
}


int main(){
    int arr[] = {1,2,3,4,5,6,5};
    cout << "The maximum sum Subarray is : " <<  maxSumSubArray(arr,7,3);

}