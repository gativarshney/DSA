// 1423. Maximum Points You Can Obtain from Cards

//? TC: O(2 * k), SC: O(1)
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int lsum = 0, rsum = 0, maxSum = 0;
        for(int i=0; i<k; i++){
            lsum += cardPoints[i];
        }
        maxSum = lsum;
        int rindex = n-1;
        for(int i = k-1; i>= 0; i--){
            lsum -= cardPoints[i];
            rsum += cardPoints[rindex];
            rindex--;
            maxSum = max(maxSum, (lsum + rsum));
        }
        return maxSum;
    }
};

// Input: cardPoints = [1,2,3,4,5,6,1], k = 3
// Output: 12

// There are several cards arranged in a row, and each card has an associated number of points. The points are given in the integer array cardPoints. In one step, you can take one card from the beginning or from the end of the row. You have to take exactly k cards. Your score is the sum of the points of the cards you have taken. Given the integer array cardPoints and the integer k, return the maximum score you can obtain.

