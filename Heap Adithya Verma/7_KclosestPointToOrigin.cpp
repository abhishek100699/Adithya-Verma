/*given (x,y) quordinates find the closest point from the origin*/
#include<bits/stdc++.h>
using namespace std;


void kClosestPoint(vector<pair<int,int>> arr,int k){
    priority_queue<pair<int , pair<int,int>>> maxh;
    for(auto x:arr){
        int key = x.first*x.second + x.second*x.second;
        maxh.push({key,x});
        if(maxh.size()>k){
            maxh.pop();
        }
    }

    while(maxh.size()>0){
        cout << maxh.top().second.first << " " << maxh.top().second.second << endl;
        maxh.pop();
    }

}



int main(){
    vector<pair<int,int>> arr = {{1,3},{-2,2},{5,8},{0,1}};
    kClosestPoint(arr, 2);
}