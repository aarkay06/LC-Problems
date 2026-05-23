class Solution {
public:
    bool check(vector<int>& nums) {
        int inc = 1;
        int last = INT_MIN;
        int changes = 0;

        for(int i =0; i<nums.size(); i++){
            if(nums[i] < last){
                changes++;
            }
            last = nums[i];
        }

        if(nums[nums.size() -1] > nums[0]) changes++;

        if(changes <= 1) return true;
        else return false;
    }
};