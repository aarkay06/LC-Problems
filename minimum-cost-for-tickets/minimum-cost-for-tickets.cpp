class Solution {
public:

    int minimum(int i, int ticketValid, vector<int>& days, vector<int>& costs, vector<vector<int>> &dp){
        if(i > days.size() -1) return 0;

        // cout << "i: " << i << " ticketValid till: " << ticketValid << "\n";
        if(dp[i][ticketValid] != -1) 
        return dp[i][ticketValid];

        int ans = INT_MAX;

        //there is a valid ticket
        if(ticketValid >= days[i]) {
            ans = minimum(i+1, ticketValid , days, costs, dp);
        }

        else {

        //choose 1 day ticket
        int r1 = costs[0] + minimum(i+1, days[i], days, costs, dp);
        int r2 = costs[1] + minimum(i+1, days[i]+6, days, costs, dp);
         int r3 = costs[2] + minimum(i+1, days[i]+29, days, costs, dp);

        ans = min(ans, min(r1, min(r2, r3)));

        }

          return dp[i][ticketValid] = ans;
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        
         vector<vector<int>> dp(days.size(), vector<int>(days[days.size() -1] +30, -1)); 
      return  minimum(0, 0, days, costs, dp);
    }
};