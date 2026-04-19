//! Greedy Algorithm - Candy
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        int i = 1, sum = 1;
        while(i < n){
            if(ratings[i] == ratings[i-1]){
                sum += 1;
                i++;
                continue;
            }
            // Increasing sequence (slope - /)
            int peak = 1;
            while(i < n && ratings[i] > ratings[i-1]){
                peak++;
                sum += peak;
                i++;
            }
            // Decreasing sequence (slope - \)
            int down = 1;
            while(i < n && ratings[i-1] > ratings[i]){
                sum += down;
                down++;
                i++;
            }
            if(down > peak){
                sum += (down - peak);
            }
        }
        return sum;
    }
};
// Time Complexity: O(n) since we are iterating through the ratings array at most once.
// Space Complexity: O(1) since we are using a constant amount of space to store

//* We iterate through the ratings array and keep track of the length of the increasing sequence (peak) and the length of the decreasing sequence (down). Whenever we encounter a rating that is greater than the previous rating, we increment the peak count and add it to the sum. Whenever we encounter a rating that is less than the previous rating, we increment the down count and add it to the sum. If at any point the down count exceeds the peak count, it means we need to give one more candy to the child at the peak of the increasing sequence, so we add (down - peak) to the sum. We continue this process until we have iterated through all ratings. Finally, we return the total sum of candies needed.


//! Brute Force Approach (TLE) - Using two passes
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> candies(n, 1);

        // 🔹 Left → Right pass
        for(int i = 1; i < n; i++){
            if(ratings[i] > ratings[i-1]){
                candies[i] = candies[i-1] + 1;
            }
        }

        // 🔹 Right → Left pass
        for(int i = n-2; i >= 0; i--){
            if(ratings[i] > ratings[i+1]){
                candies[i] = max(candies[i], candies[i+1] + 1);
            }
        }

        // 🔹 Sum all candies
        int sum = 0;
        for(int c : candies){
            sum += c;
        }

        return sum;
    }
};
// Time Complexity: O(3*n) since we are iterating through the ratings array twice and then summing up the candies.
// Space Complexity: O(n) since we are using an additional array to store the number of candies for each child.