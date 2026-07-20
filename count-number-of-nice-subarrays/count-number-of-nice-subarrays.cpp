class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        if (nums[0] % 2 == 0)
            nums[0] = 0;
        else
            nums[0] = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] % 2 != 0)
                nums[i] = 1 + nums[i - 1];
            else
                nums[i] = nums[i - 1];
        }

        unordered_map<int, int> m;
        int count = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == k)
                count++;

            if (m.contains(nums[i] - k)) {
                count += m[nums[i] - k];
            }

            m[nums[i]]++;
        }
        return count;
    }
};