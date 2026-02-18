#include<bits/stdc++.h>
using namespace std;

void print(int idx, vector<int> &ds, vector<int> &arr, int n){
    if(idx == n){
        for(auto it : ds){
            cout << it << " ";
        }
        if(ds.size() == 0) cout << "{}";
        cout << endl;
        return;
    }
    // take or pick the particular index into subsequence
    ds.push_back(arr[idx]);
    print(idx+1, ds, arr, n);
    ds.pop_back();

    // not pick or not take condition, means this element is not added into the subsequence
    print(idx+1, ds, arr, n);
}

int main(){
    vector<int> arr = {3, 1, 2};
    int n = arr.size();
    vector<int> ds;
    print(0, ds, arr, n);
    return 0;
}

//* Time Complexity : O(2^n * n)
//* Space Complexity : O(n) for recursion stack space

//! n elements --> 2^n subsequence