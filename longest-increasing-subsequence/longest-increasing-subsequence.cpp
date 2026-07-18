class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(), vector<int>(nums.size(), -1)); 
        return subsequence(0, -1, nums, dp);
    }

    int subsequence(int i, int prev, vector<int>& nums,  vector<vector<int>> &dp) {
        if(i == nums.size()) return 0;
        if(dp[i][prev+1] != -1) return dp[i][prev+1];
        // pick
        int pick =0, notpick=0;
        if (prev == -1 || nums[i] > nums[prev]) {
            pick = 1 + subsequence(i + 1, i, nums, dp);
        }
        // not pick
        notpick = 0 + subsequence(i + 1, prev, nums, dp);

        return dp[i][prev+1] = max(pick, notpick);
    }
};