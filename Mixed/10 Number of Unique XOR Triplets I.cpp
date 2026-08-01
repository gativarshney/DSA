class Solution {
    int countBits(int n){
        int cnt = 0;

        while(n > 0){
            n = n / 2;
            cnt++;
        }

        return cnt;
    }
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();

        if(n < 3) return n;

        int k = countBits(n);

        return 1 << k;
    }
};

// 1 << k because the number of unique XOR triplets can be represented as 2^k, where k is the number of bits required to represent the size of the input array. This is derived from the fact that each bit can either be 0 or 1, leading to 2^k combinations.