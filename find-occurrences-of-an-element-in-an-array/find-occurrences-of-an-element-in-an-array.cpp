class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries,
                                     int x) {
        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == x) {
                nums[count] = i;
                count++;
            }
        }

        for (int i = 0; i < queries.size(); i++) {
            if (queries[i] > count) {
                queries[i] = -1;
            } else
                queries[i] = (nums[queries[i] - 1]);
        }
        return queries;
    }
};