//! Brute Force
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        double ans;
        int m = nums1.size(), n = nums2.size();
        vector<int> nums(m+n);
        for(int i=0; i<m; i++){
            nums[i] = nums1[i];
        }
        for(int j=0; j<n; j++){
            nums[j+m] = nums2[j];
        }
        sort(nums.begin(), nums.end());
        int k = m + n;
        if(k % 2 == 1){
            int index = k/2;
            ans = nums[index];
        }
        else{
            int idx1 = k/2 - 1, idx2 = k/2;
            ans = (nums[idx1] + nums[idx2]) / 2.0;
        }
        return ans;
    }
};
// TC: O(m + n log(m + n))
// SC: O(m + n)


//! Better Approach
class Solution {
    void merge(vector<int>& nums1, vector<int>& nums2, vector<int> &nums){
        int m = nums1.size(), n = nums2.size();
        int i = 0, j = 0;

        while(i < m && j < n){
            if(nums1[i] < nums2[j]){
                nums.push_back(nums1[i]);
                i++;
            }
            else{
                nums.push_back(nums2[j]);
                j++;
            }
        }
        while(i < m){
            nums.push_back(nums1[i]);
            i++;
        }
        while(j < n){
            nums.push_back(nums2[j]);
            j++;
        }
    }
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        
        vector<int> nums;

        merge(nums1, nums2, nums);

        double ans = 0;
        int k = m + n;

        if(k % 2 == 1){
            int index = k/2;
            ans = nums[index];
        }
        else{
            int idx1 = k/2 - 1, idx2 = k/2;
            ans = (nums[idx1] + nums[idx2]) / 2.0;
        }

        return ans;
    }
};
// Time Complexity: O(m + n)
// Space Complexity: O(m + n)

//! Optimised Solution (Binary Search)
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();

        if(n1 > n2) return findMedianSortedArrays(nums2, nums1);

        int low = 0, high = n1;
        int left = (n1 + n2 + 1) / 2;
        int n = n1 + n2;

        while(low <= high){
            int mid1 = low + (high - low) / 2;
            int mid2 = left - mid1;

            int l1 = INT_MIN, l2 = INT_MIN;
            int r1 = INT_MAX, r2 = INT_MAX;

            if(mid1 < n1) r1 = nums1[mid1];
            if(mid2 < n2) r2 = nums2[mid2];

            if(mid1 > 0) l1 = nums1[mid1 - 1];
            if(mid2 > 0) l2 = nums2[mid2 - 1];

            if(l1 <= r2 && l2 <= r1){
                if(n % 2 == 1){
                    return max(l1, l2);
                }
                else{
                    double ans = ((double)(max(l1, l2)) + (double)(min(r1, r2))) / 2.0;
                    return ans;
                }
            }
            else if(l1 > r2){
                high = mid1 - 1;
            }
            else low = mid1 + 1;
        }
        
        return 0;
    }
};


//* TC: O(log(min(n1, n2)))
//* SC: O(1)




//? NOTE:
/*
Optimal Approach: Binary Search on Partition

Idea:
Instead of searching for the median, search for the correct partition.

Partition both arrays such that:
1. Left half contains (n1 + n2 + 1) / 2 elements.
2. Every element in the left half <= every element in the right half.

Conditions for a valid partition:
    l1 <= r2
    l2 <= r1

where:
    l1 = last element of left part of nums1
    r1 = first element of right part of nums1
    l2 = last element of left part of nums2
    r2 = first element of right part of nums2

Example:
nums1 = [1,3]
nums2 = [2,4]

Correct Partition:

nums1 : [1 | 3]
nums2 : [2 | 4]

Left  = [1,2]
Right = [3,4]

l1 = 1
r1 = 3
l2 = 2
r2 = 4

Check:
1 <= 4 ✔
2 <= 3 ✔

Even length:
Median = (max(l1,l2) + min(r1,r2)) / 2
       = (2 + 3) / 2 = 2.5

---------------------------------------------------

Example (Odd Length):

nums1 = [1,3]
nums2 = [2]

After swapping (always binary search on smaller array):

nums1 = [2]
nums2 = [1,3]

Partition:

nums1 : [2 | ]
nums2 : [1 | 3]

Left  = [1,2]
Right = [3]

l1 = 2
r1 = INF
l2 = 1
r2 = 3

2 <= 3 ✔
1 <= INF ✔

Odd length:
Median = max(l1,l2) = 2

---------------------------------------------------

Binary Search:
l1 > r2  -> move left  (high = mid1 - 1)
l2 > r1  -> move right (low = mid1 + 1)

Always binary search on the smaller array.

Time: O(log(min(n1,n2)))
Space: O(1)
*/

//! For high and low movements:
/*
Binary Search Movement:

Suppose the partitions are:

nums1 : [ ... l1 | r1 ... ]
nums2 : [ ... l2 | r2 ... ]

Need:
l1 <= r2 && l2 <= r1

------------------------------------------------

Case 1: l1 > r2

nums1 : [1 3 8 | 9 15]
nums2 : [7 11 | 18 19]

l1 = 8
r2 = 18   (valid)

Imagine instead:
l1 = 15
r2 = 11

15 > 11 ❌

Left part of nums1 has taken too many large elements.
Move partition in nums1 LEFT.

high = mid1 - 1

------------------------------------------------

Case 2: l2 > r1

nums1 : [1 3 | 8 9]
nums2 : [7 11 | 18 19]

Suppose:
l2 = 11
r1 = 8

11 > 8 ❌

Left part of nums1 has too few elements.
Move partition in nums1 RIGHT.

low = mid1 + 1

------------------------------------------------

Memory Trick:

l1 > r2
=> nums1 left is TOO BIG
=> Move LEFT
=> high--

l2 > r1
=> nums1 left is TOO SMALL
=> Move RIGHT
=> low++
*/
