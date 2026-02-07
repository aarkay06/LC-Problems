class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int len = 0;
        int i = 0;
        int zeroes = 0;
        for (int j = 0; j < nums.size(); j++) {
            if (nums[j] == 0) {
                zeroes++;
            } 
            len = max(len, j - i + 1 - zeroes);
            while(zeroes > 1){
                if(nums[i]==0)
                zeroes--;
                i++;
            }
        }
        return (len == nums.size() ? nums.size() - 1 : len);
    }
};
