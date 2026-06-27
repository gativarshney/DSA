//* Search Element in a Rotated Sorted Array
//Identify the sorted part (left or right)

#include<bits/stdc++.h>
using namespace std;

int search(vector<int> & arr, int k){
    int n = arr.size();
    int low = 0, high = n-1;
    while(low <= high){
        int mid = low + (high - low)/2;
        if(arr[mid] == k) return mid;
        // Left Half Sorted
        if(arr[low] <= arr[mid]){
            if(arr[low] <= k && k <= arr[mid]){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        // Right Half Sorted
        else{
            if(arr[mid] <= k && k <= arr[high]){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
    }
    return -1;
}
int main(){
    int n;
    int target;
    vector<int> arr;
    cout << "Enter size of Array : ";
    cin >> n;
    cout << "Enter elements of Rotated Sorted Array : ";
    for(int i=0; i<n; i++){
        int x;
        cin >> x;
        arr.push_back(x);
    }
    cout << "Enter element to be search in Rotated Sorted Array : ";
    cin >> target;

    int index = search(arr, target);
    if(index == -1) cout << "Element not found!" << endl;
    else cout << "Element found at index : " << index << endl;
    return 0;
}

// TC for Unique: O(logN)