class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;
        if (nums.size() == 1)
            return nums[0];
        if (nums.size() == 2)
            return max(nums[0], nums[1]);

        int last = max(nums[0], nums[1]);
        int lSecond = nums[0];

        int res;
        for (int i = 2; i < nums.size() - 1; i++) {
            int temp = lSecond;
            lSecond = last;
            last = max(last, temp + nums[i]);
        }

        res = last;

        last = max(nums[1], nums[2]);
        lSecond = nums[1];

        
        for (int i = 3; i < nums.size(); i++) {
            int temp = lSecond;
            lSecond = last;
            last = max(last, temp + nums[i]);
        }

        res = max(last, res);
        return res;
    }
};