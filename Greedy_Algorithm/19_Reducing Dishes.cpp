class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        int n = satisfaction.size();

        sort(satisfaction.begin(), satisfaction.end());

        int suffixSum = 0;
        int ans = 0;
        
        for(int i = n-1; i >= 0; i--){
            suffixSum += satisfaction[i];

            if(suffixSum <= 0) break;
            else ans += suffixSum;
        }

        return ans;
    }
};
// TC: O(nlogn) due to sorting the satisfaction array   
// SC: O(1) for the variables used to calculate the answer

//* Intution:
// Score can be viewed as the sum of all suffix sums:
// (a1+...+ak) + (a2+...+ak) + ... + ak
//
// Traverse from right to left and maintain suffixSum.
// If suffixSum > 0, it contributes positively to the answer.
// Once suffixSum <= 0, further elements can only decrease it,
// so stop.

//! It can also be solved using DP but the greedy approach is more efficient in terms of time and space complexity.

// Example: [-1, 2, 5] here as we go on 5 will get sum in suffixSum 3 times, 2 will get sum in suffixSum 2 times and -1 will get sum in suffixSum 1 time. So the answer is 5*3 + 2*2 + (-1)*1 = 15 + 4 - 1 = 18. We included -1 becoz as suffixSum is still positive after including -1, it contributes positively to the answer.

