class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        if(nums.size() == 1) return nums[0];
        if(nums.size() == 2) return max(nums[0], nums[1]);

        int last = max(nums[0], nums[1]);
        int lSecond = nums[0];
       for (int i = 2; i < nums.size(); i++) {
        int temp = lSecond;
        lSecond = last;
        last = max(last, temp + nums[i]);
       }

       return last;
    }
};