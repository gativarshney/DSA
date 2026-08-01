class Solution {
    bool canChoose(int limit, vector<int> &nums, int k){
        int n = nums.size();

        int need = nums[0] + limit;
        int cnt = 1;

        for(int i = 1; i < n; i++){

            if(nums[i] >= need){
                cnt++;
                need = nums[i] + limit;

                if(cnt == k) return true;
            }
        }

        return false;
    }
public:
    int maximumTastiness(vector<int>& price, int k) {
        int n = price.size();

        sort(price.begin(), price.end());

        int maxi = price[n-1];
        int mini = price[0];

        int low = 0;
        int high = maxi - mini;

        while(low <= high){
            int mid = low + (high - low) / 2;

            if(canChoose(mid, price, k)){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }

        return high;
    }
};