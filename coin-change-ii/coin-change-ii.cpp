class Solution {
public:
    int change(int amount, vector<int>& coins) {
         vector<vector<int>> dp(coins.size(), vector<int>(amount+1, -1)); 

    return ways(0, coins, amount, dp);
    }

    int ways(int i, vector<int>& coins, int amount, vector<vector<int>> &dp){

        if(amount == 0) return 1;
        if(i >= coins.size()) return 0;
        if(dp[i][amount] != -1) return dp[i][amount];

        int pick =0, notpick=0;
        //pick
        if(coins[i] <= amount) 
            pick = ways(i, coins, amount - coins[i], dp);

        //not pick
        notpick = ways(i+1, coins, amount, dp);

        return dp[i][amount] = pick+notpick;
    }
};