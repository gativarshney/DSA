#include<bits/stdc++.h>
using namespace std;

int kthElement(vector<int> &arr1, vector<int>& arr2, int n, int m, int k){

    if(n > m) return kthElement(arr2, arr1, m, n, k);

    int low = max(0, k - m);    // if k = 7 and m = 5 then arr1 have to give 2 element for sure
    int high = min(k, n);       // if k = 7 and n = 10 then arr1 can only give upto 7 elements
    int left = k;

    while(low <= high){
        int mid1 = low + (high - low) / 2;
        int mid2 = left - mid1;

        int l1 = INT_MIN, l2 = INT_MIN;
        int r1 = INT_MAX, r2 = INT_MAX;

        if(mid1 < n) r1 = arr1[mid1];
        if(mid2 < m) r2 = arr2[mid2];

        if(mid1 > 0) l1 = arr1[mid1 - 1];
        if(mid2 > 0) l2 = arr2[mid2 - 1];

        if(l1 <= r2 && l2 <= r1){
            return max(l1, l2);
        }
        else if(l1 > r2){
            high = mid1 - 1;
        }
        else low = mid1 + 1;
    }
    
    return 0;
}

//* TC: O(log(min(n, m)))
//* SC: O(1)