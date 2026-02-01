class Solution {
public:
    int findMin(vector<int>& nums) {
        int min = nums[0];
        int start = 0;
        int end = nums.size()-1;
        while(start<= end){
            int mid =(start+end)/2;
            if(nums[mid] < min) min = nums[mid];
            if(nums[start] <= nums[mid]){
                if(nums[start] < min) min = nums[start];
                start = mid+1;
            }
            else{
                 if(nums[start] < min) min = nums[start];
                 end= mid-1;
            }
        }
        return min;
    }
};