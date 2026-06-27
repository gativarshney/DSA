//* Find square root of a number in log n
// Given a non-negative integer x, return the square root of x rounded down to the nearest integer. The returned integer should be non-negative as well.

//? Using Binary Search
int mySqrt(int x) {
    if(x == 0) return 0;
    long long int low = 1;
    long long int high = x;
    long long int ans = 1;
    while(low <= high){
        long long int mid = low + (high - low)/2;
        long long int square = mid * mid;
        if(square == x) return mid;
        else if(square < x){
            low = mid+1;
            ans = max(ans, mid);
        } 
        else high = mid-1;
    }
    return ans;
}
// Or simply
int mySqrt(int x) {
    int low = 1, high = x;
    while(low <= high){
        long long int mid = low + (high - low)/2;
        long long int square = mid * mid;
        if(square <= x){
            low = mid+1;
        } 
        else high = mid-1;
    }
    return high;        // high will always point to the ans, try test cases
}