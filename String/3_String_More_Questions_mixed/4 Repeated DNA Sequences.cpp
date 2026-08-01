class Solution {

    // Map DNA characters to integers
    int value(char ch){
        if(ch == 'A') return 1;
        if(ch == 'C') return 2;
        if(ch == 'G') return 3;
        return 4;       // T
    }

public:
    vector<string> findRepeatedDnaSequences(string s) {

        int n = s.size();

        if(n < 10) return {};

        vector<string> ans;

        int p = 7;
        int mod = 1000000007;

        // pr = p^(windowSize-1)
        // Needed to remove the contribution of the leftmost character.
        int pl = 1, pr = 1;

        // Polynomial rolling hash:
        // hash = c0*p^(k-1) + c1*p^(k-2) + ... + ck
        int hash = 0;

        // Compute hash of first 10-character window.
        for(int i = 0; i < 10; i++){
            hash = (1LL * hash * p + value(s[i])) % mod;

            // After loop, pr becomes p^9.
            // (Don't multiply on last iteration, otherwise it becomes p^10.)
            if(i != 9)
                pr = (1LL * pr * p) % mod;
        }

        // Hash -> all strings having this hash.
        // Vector is used to safely handle rare hash collisions.
        unordered_map<long long, vector<string>> mpp;

        mpp[hash].push_back(s.substr(0, 10));

        // Slide the window one character at a time.
        for(int i = 10; i < n; i++){

            // Remove contribution of leftmost character.
            hash = (hash - 1LL * value(s[i - 10]) * pr % mod + mod) % mod;

            // Shift remaining hash left by one power and add new character.
            hash = (1LL * hash * p + value(s[i])) % mod;

            string window = s.substr(i - 9, 10);

            bool found = false;

            // Verify actual strings to avoid hash collision issues.
            for(auto &str : mpp[hash]){
                if(str == window){
                    found = true;
                    break;
                }
            }

            if(found)
                ans.push_back(window);

            // Store current window for future comparisons.
            mpp[hash].push_back(window);
        }

        // Remove duplicates because the same sequence
        // may appear more than twice.
        sort(ans.begin(), ans.end());
        ans.erase(unique(ans.begin(), ans.end()), ans.end());

        return ans;
    }
};

// Window size = 5

// Current window:
// ABCDE
// Hash = A*p⁴ + B*p³ + C*p² + D*p¹ + E*p⁰

// Next window:
// BCDEF
// We want:
// B*p⁴ + C*p³ + D*p² + E*p¹ + F*p⁰

// Step 1: Remove A
// hash = B*p³ + C*p² + D*p¹ + E*p⁰

// Step 2: Shift all remaining characters one power left
// hash = (B*p³ + C*p² + D*p¹ + E*p⁰) * p
//      = B*p⁴ + C*p³ + D*p² + E*p¹

// Step 3: Add new character
// hash = B*p⁴ + C*p³ + D*p² + E*p¹ + F*p⁰