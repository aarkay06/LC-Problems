
class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {

        for (int i = 1; i < nums.size(); i++) {
            nums[i] = nums[i - 1] + nums[i];
        }

        int count = 0;
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == goal)
                count++;

            if (m.contains(nums[i] - goal))
                count += m[nums[i] - goal];

            m[nums[i]]++;
        }

        return count;
    }
};