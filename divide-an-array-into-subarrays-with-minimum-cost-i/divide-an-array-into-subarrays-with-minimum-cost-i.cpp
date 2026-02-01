class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int firstSubArray = 1;
        int secondSubArray = 2;

        if (nums[1] < nums[2]) {
            firstSubArray = 1;
            secondSubArray = 2;
        } else {
            firstSubArray = 2;
            secondSubArray = 1;
        }

        for (int i = 3; i < nums.size(); i++) {
            if (nums[i] < nums[secondSubArray]) {

                if (nums[i] < nums[firstSubArray]) {
                    secondSubArray = firstSubArray;
                    firstSubArray = i;
                } else {
                    secondSubArray = i;
                }
            }
        }
         return nums[0] + nums[firstSubArray] + nums[secondSubArray];
    }
};