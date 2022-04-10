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

int main(){
    vector<int> arr = {6,2,5,4,5,1,6};
    vector<int> left = NSL(arr);
    vector<int> right = NSR(arr);
    vector<int> width ;
    cout << "Left array : " ;
    for(auto x: left){
        cout << x << " " ;
    }
    cout << endl;

    cout << "Right array : " ;
    for(auto x: right){
        cout << x << " " ;
    }
    cout << endl;
// finding the width array.
    for(int i=0;i<arr.size();i++){
        width.push_back(right[i]-left[i]-1);
    }

    cout << "Width array : " ;
    for(auto x:width){
        cout << x << " " ;
    }
    cout << endl;
    priority_queue<int> ans;
    for(int i=0;i<arr.size();i++){
        ans.push(width[i]*arr[i]);
    }
    cout << "Maximum area " << ans.top();
}