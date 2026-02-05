class Solution {
public:
    int search(vector<int>& nums, int t) {
        int start = 0;
        int end = nums.size() - 1;
        int last = nums[nums.size() - 1];

        while (start <= end) {
            int mid = (start + end) / 2;

            if (nums[mid] == t)
                return true;

            if(nums[mid] == nums[start] && nums[start] == nums[end]){
                end--;
                start++;
                continue;
            }
            if (nums[start] <= nums[mid]) {
                if (nums[start] <= t && t < nums[mid]) {
                    end = mid - 1; 
                } else {
                    start = mid + 1; 
                }
            }
            else {
                if (nums[mid] < t && t <= nums[end]) {
                    start = mid + 1;
                } else {
                    end = mid - 1; 
                }
            }
        }
        return false;
    }
};