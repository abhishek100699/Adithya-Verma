#include<bits/stdc++.h>
using namespace std;

// finding next smaller element index in the left 
vector<int> NSL(vector<int> arr){
    vector<int> v;
    stack<pair<int,int>> s;
    int pseudo_indx = -1;
    for(int i=0;i<arr.size();i++){
        if(s.size()==0){
            v.push_back(pseudo_indx);
        }
        else{
            if(s.top().first<arr[i]){
                v.push_back(s.top().second);
            }
            else if(s.top().first >= arr[i]){
                while(s.size()>0 && s.top().first>=arr[i]){
                    s.pop();
                }
                if(s.size()==0){
                    v.push_back(pseudo_indx);
                }
                else{
                    v.push_back(s.top().second);
                }
            }
        }
        s.push({arr[i],i});
    }
    return v;
}


// finding nearest smaller element index in the right

vector<int> NSR(vector<int> arr){
    vector<int> v;
    stack<pair<int,int>> s;
    int pseudo_indx = arr.size();
    for(int i=arr.size()-1;i>=0;i--){
        if(s.size()==0){
            v.push_back(pseudo_indx);
        }
        else{
            if(s.top().first<arr[i]){
                v.push_back(s.top().second);
            }
            else if(s.top().first >= arr[i]){
                while(s.size()>0 && s.top().first>=arr[i]){
                    s.pop();
                }
                if(s.size()==0){
                    v.push_back(pseudo_indx);
                }
                else{
                    v.push_back(s.top().second);
                }
            }
        }
        s.push({arr[i],i});
    }
    reverse(v.begin(),v.end());
    return v;
}



int MAH(vector<int> v){
    vector<int> left  = NSL(v);
    vector<int> right = NSR(v);
    vector<int> width;
    for(int i=0;i<v.size();i++){
        width.push_back(right[i]-left[i]-1);
    }
    priority_queue<int> ans;
    for(int i=0;i<v.size();i++){
        ans.push(width[i]*v[i]);
    }
    return ans.top();
}


int main(){
    vector<vector<int>> arr = {{0,1,1,0},{1,1,1,1},{1,1,1,1},{1,1,0,0}};
    int m = arr.size();
    int n = arr[0].size();
    vector<int> v;
    for(int j=0;j<m;j++){
        v.push_back(arr[0][j]);
    }
    int maxarea = MAH(v);
    for(int i=1;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j]==0){
                v[j] = 0;
            }
            else{
                v[j] = v[j] + arr[i][j];
            }
        }
        maxarea = max(maxarea,MAH(v));
    }
    cout << "Maximum area of the binaray rectangle is : " << maxarea;
}