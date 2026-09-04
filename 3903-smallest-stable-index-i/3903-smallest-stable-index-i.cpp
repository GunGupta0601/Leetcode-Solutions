class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> suffixMin(n);
        suffixMin[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            suffixMin[i] = min(nums[i], suffixMin[i + 1]);
        }
        int maxLeft = INT_MIN;
        for (int i = 0; i < n; i++) {
            maxLeft = max(maxLeft, nums[i]);
            int minRight = suffixMin[i];
            if (maxLeft - minRight <= k) {
                return i;
            }
        }
        return -1;
    }
};