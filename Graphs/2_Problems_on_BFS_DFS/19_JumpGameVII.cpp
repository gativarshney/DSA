class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.length();

        if(s[n-1] != '0') return false;

        queue<int> q;
        q.push(0);

        vector<int> vis(n, 0);
        vis[0] = 1;

        int farthest = 0;

        while(!q.empty()){
            int idx = q.front();
            q.pop();

            if(idx == n-1) return true;

            int start = max(idx + minJump, farthest);
            int end = min(idx + maxJump, n-1);

            for(int i = start; i <= end && i < n; i++){
                if(s[i] == '0' && vis[i] == 0){
                    q.push(i);
                    vis[i] = 1;
                }
            }

            farthest = end + 1;
        }

        return false;
    }
};

//* Time Complexity: O(n)
//* Space Complexity: O(n)

/**
Why farthest Works

Suppose:

index 2 already checked range [5...10]
later index 3 again wants to check [6...11]

Without farthest, you rescan 6...10.

With farthest, you directly start from 11.

That’s the key optimization.
*/