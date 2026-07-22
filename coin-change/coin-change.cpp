class Solution {
public:
    int minCoins(int i, vector<int>& coins, int amount, vector<vector<int>>& dp) {
        
        if (amount == 0)
            return 0;
        if (i < 0)
            return 1e8;

        if(dp[i][amount] != -1) return dp[i][amount];   

        int take =1e8, nottake;

        nottake = minCoins(i - 1, coins, amount, dp);

        if (coins[i] <= amount)
            take = 1 + minCoins(i, coins, amount - coins[i], dp);

        return dp[i][amount] =  min(take, nottake);
    }

    int coinChange(vector<int>& coins, int amount) {
         vector<vector<int>> dp(coins.size(), vector<int>(amount+1, -1)); 
        int ans = minCoins(coins.size() - 1, coins, amount, dp);
        if (ans == 1e8)
            return -1;

        return ans;
    }
};