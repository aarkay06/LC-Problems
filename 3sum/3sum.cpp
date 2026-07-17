class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> mySet;
        sort(nums.begin(), nums.end());


        for (int i = 0; i < nums.size(); i++) {
            if(i > 0 && nums[i-1] == nums[i]) continue;
            int target = 0 - (nums[i]);
            int j = 0;
            int k = nums.size() - 1;
            while (j < k) {
               if(i == j) j++;
               if (i == k) k--;
               if(j ==k) break;
                if (nums[j] + nums[k] == target) {
                    vector<int> v = {nums[i], nums[j], nums[k]};
                    sort(v.begin(), v.end());
                    mySet.insert(v);
                }
                if (nums[j] + nums[k] > target)
                    k--;
                else
                    j++;
            }
        }
        vector<vector<int>> res;

        for (const auto& element : mySet) {
            res.push_back(element);
        }

        return res;
    }
};