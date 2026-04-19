// ❌ DP / brute force → TLE
// ✅ Optimized using Math + Range Counting (Combinatorics Thinking)

class Solution {
public:
    long long distributeCandies(int n, int limit) {
        long long ways = 0;

        // Fix i = candies given to 1st child
        // i can be at most min(n, limit)
        for(int i = 0; i <= min(n, limit); i++){

            // Remaining candies to distribute:
            // j + k = n - i

            // We derive valid range of j using constraints:
            // 0 ≤ j ≤ limit
            // 0 ≤ k = n - i - j ≤ limit

            // From k ≥ 0  → j ≤ n - i
            // From k ≤ limit → j ≥ n - i - limit

            // Combine all constraints:
            int left  = max(0, n - i - limit);   // lower bound of j // Think age >= 5 and age >= 10 => age >= max(5, 10)
            int right = min(limit, n - i);       // upper bound of j // Think age <= 5 and age <= 10 => age <= min(5, 10)

            // If valid range exists
            if(left <= right){

                // Number of valid j values in [left, right]
                // count = (right - left + 1)
                ways += (right - left + 1);
            }
        }
        return ways;
    }
};

/*
🧠 CORE IDEA:

We need:
    i + j + k = n
    0 ≤ i, j, k ≤ limit

Step 1:
Fix i → reduces problem to:
    j + k = n - i

Step 2:
Instead of looping j & k (O(n²)),
→ compute valid range of j directly

Step 3:
Count valid j using formula:
    count = right - left + 1

--------------------------------------

⚡ COMPLEXITY:

Time:  O(n)      (loop over i only)
Space: O(1)

--------------------------------------

🔥 KEY PATTERN (IMPORTANT FOR INTERVIEWS):

Whenever:
    x + y + z = constant

→ Fix one variable
→ Convert others into range constraints
→ Count instead of iterate

--------------------------------------

🚫 COMMON MISTAKES:

1. Trying all (i, j, k) → O(n³)
2. Not deriving bounds properly
3. Forgetting "+1" in (right - left + 1)

--------------------------------------

💡 TAGS:
Math, Combinatorics, Range Counting, Optimization
*/