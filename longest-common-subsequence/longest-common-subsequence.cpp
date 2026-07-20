class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
         vector<vector<int>> dp(text1.size()+1, vector<int>(text2.size()+1, -1)); 
         return subSequence(0,0, text1, text2, dp);
    }

    int subSequence(int i, int j, string &s1, string &s2, vector<vector<int>> &dp){
            if(i >= s1.size() ||  j>= s2.size()) return 0;
            if(dp[i][j] != -1) return dp[i][j];

            if(s1[i] == s2[j])
            return dp[i][j] = ( 1 + subSequence(i+1, j+1, s1, s2, dp));
            else 
            return dp[i][j] = max(
                subSequence(i+1, j, s1, s2, dp), 
                subSequence(i, j+1, s1, s2, dp)
            );
    }
};