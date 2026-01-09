//* Koko Eating Bananas

// ! Brute Force

Java
Python
JavaScript





#include <bits/stdc++.h>
using namespace std;

int findMax(vector<int> &v) {
    int maxi = INT_MIN;
    int n = v.size();
    for (int i = 0; i < n; i++) {
        maxi = max(maxi, v[i]);
    }
    return maxi;
}

int calculateTotalHours(vector<int> &v, int hourly) {
    int totalH = 0;
    int n = v.size();
    for (int i = 0; i < n; i++) {
        totalH += ceil((double)(v[i]) / (double)(hourly));
    }
    return totalH;
}

int minimumRateToEatBananas(vector<int> v, int h) {
    int maxi = findMax(v);
    for (int i = 1; i <= maxi; i++) {
        int reqTime = calculateTotalHours(v, i);
        if (reqTime <= h) {
            return i;
        }
    }
    return maxi;
}
// TC: O(maxi * n)  where maxi = max(array Element), n = size of array

//! *****************************************************************

// * Optimal Solution

int findMax(vector<int>& piles){
    int maxi = INT_MIN;
    int n = piles.size();
    for(int i=0; i<n; i++){
        maxi = max(maxi, piles[i]);
    }
    return maxi;
}
long long int totalHours(vector<int>& piles, int mid){
    int n = piles.size();
    long long int hours = 0;
    for(int i=0; i<n; i++){
        hours += ceil((double)piles[i] / (double) mid);
    }
    return hours;
}
int minEatingSpeed(vector<int>& piles, int h) {
    int n = piles.size();
    int low = 1;
    int high = findMax(piles);
    int k = 0;
    while(low <= high){
        int mid = low + (high - low)/2;
        long long int hours = totalHours(piles, mid);
        if(hours <= h){
            k = mid;
            high = mid-1;
        }
        else low = mid+1;
    }
    return k;
}
// TC : O(log(maxElem) * n) where n is size of piles array