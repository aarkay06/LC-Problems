
class Solution
{
public:
    int numSubarraysWithSum(vector<int> &nums, int goal)
    {

        int count = 0;
        for (int i = 1; i < nums.size(); i++)
        {
            nums[i] = nums[i - 1] + nums[i];
        }

        for (int i = (goal - 1) > 0 ? goal - 1 : 0; i < nums.size(); i++)
        {
            // arr[i] - arr[j] = goal
            if (nums[i] < goal)
                continue;

            int j = (nums[i] - goal - 1 >= 0) ? nums[i] - goal - 1 : 0;

            if (nums[i] == goal)
                count++;
            while (j < i)
            {

                if (nums[i] - nums[j] == goal)
                    count++;
                if (nums[i] - nums[j] < goal)
                    break;
                j++;
            }
        }
        return count;
    }
};