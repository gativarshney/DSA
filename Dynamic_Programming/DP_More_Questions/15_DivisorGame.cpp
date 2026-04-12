class Solution {
    bool solve(int n){
        if(n <= 1) return false;
        for(int x = 1; x < n && n % x == 0; x++){
            if(solve(n-x) == false) return true;
        }
        return false;
    }
public:
    bool divisorGame(int n) {
        return solve(n);
    }
};
//* Time Complexity: O(2^n) in the worst case, as the function can explore all possible combinations of moves. However, due to the nature of the game, it will not actually reach this complexity for larger values of n, as many branches will terminate early.
//* Space Complexity: O(n) due to the recursive call stack


//! Optimal Solution: The game can be solved using a simple mathematical observation. Alice wins if n is even, and Bob wins if n is odd. This is because Alice can always subtract 1 from an even number to make it odd for Bob, and Bob can only subtract from an odd number to make it even for Alice. Therefore, the optimal solution is:
class Solution {
public:
    bool divisorGame(int n) {
        if(n % 2 == 0) return true;
        return false;
    }
};
//* Time Complexity: O(1) as we are just checking if n is even or odd.
//* Space Complexity: O(1) as we are using only a constant amount of space.