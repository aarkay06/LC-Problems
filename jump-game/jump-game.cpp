class Solution {
public:
    bool canJump(vector<int>& nums) {
        int jumpHeight = 0;
        for(int i =0; i< nums.size() -1; i++){
            jumpHeight = max(jumpHeight-1, nums[i] );
            if(jumpHeight == 0 ) break;
        }

        if(jumpHeight ||nums.size() == 1 ) return true;
        else return false;
    }
};