//! Brute force approach: find the product of all elements in the array, then find the distinct prime factors of the product.
class Solution {
public:
    int distinctPrimeFactors(vector<int>& nums) {
        int n = nums.size();
        long long product = 1;
        int cnt = 0;
        for(int i = 0; i < n; i++){
            product = (1LL * product * nums[i]);
        }
        for(int i = 2; i*i <= product; i++){
            if(product % i == 0){
                cnt++;
                while(product % i == 0){
                    product = product / i;
                }
            }
        }
        if(product > 1) cnt++;
        return cnt;
    }
};
// Time Complexity: O(n + sqrt(product))
// Space Complexity: O(1)
//? But it will not work for large values of product, as it can overflow. So we need to find a better approach.


//! Optimized approach: find the distinct prime factors of each element in the array and store them in a set. The size of the set will give us the count of distinct prime factors of the product of the array. As we know product of two numbers will have distinct prime factors as the union of distinct prime factors of both the numbers. So we can find the distinct prime factors of each element in the array and store them in a set. The size of the set will give us the count of distinct prime factors of the product of the array.
class Solution {
public:
    int distinctPrimeFactors(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> st;
        for(int i = 0; i < n; i++){
            int num = nums[i];
            for(int j = 2; j*j <= num; j++){
                if(num % j == 0){
                    st.insert(j);
                    while(num % j == 0){
                        num = num / j;
                    }
                }
            }
            if(num > 1) st.insert(num);
        }
        return st.size();
    }
};
// Time Complexity: O(n * sqrt(max(nums[i])))
// Space Complexity: O(k) where k is the number of distinct prime factors in the product