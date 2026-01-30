class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        int first = 0;
        int end = nums.size() -1;
        int firstOcc = -1, mid;

        while(first<=end){
        	mid = (first + end)/2;
        	if( nums[mid] == target){
        		firstOcc = mid;
            	end = mid - 1;
        	}
        	if(nums[mid] > target){
        		end = mid-1; 
        	}
        	if(nums[mid] < target){
        		first = mid + 1;
        	}
        }


		 first = 0;
         end = nums.size() -1;
        int lastOcc =-1;

        while(first<=end){
        	mid = (first + end)/2;
        	if( nums[mid] == target){
        		lastOcc = mid;
        		first = mid + 1;
        	}
        	if(nums[mid] > target){
        		end = mid-1; 
        	}
        	if(nums[mid] < target){
        		first = mid + 1;
        	}
        }
        ans.push_back(firstOcc);
        ans.push_back(lastOcc);
        return ans;
    }

};