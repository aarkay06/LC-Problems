#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int sortAt = 0;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] < nums[i - 1])
            {
                sortAt = i;
                break;
            }
        }

        cout << "rotated at: " << sortAt << endl;

        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + nums.size() - sortAt);
        reverse(nums.begin() + nums.size() - sortAt, nums.end());

        for (int x : nums)
        {
            cout << x << " ";
        }

        int start = 0;
        int end = nums.size() - 1;

        while (start <= end)
        {
            int mid = (start + end) / 2;
            cout << "\nmid: " << mid << endl;
            if (target == nums[mid])
            {
                return (mid + sortAt) % (nums.size());
            }
            else if (target > nums[mid])
                start = mid + 1;
            else
                end = mid - 1;
        }
        return -1;
    }
};
