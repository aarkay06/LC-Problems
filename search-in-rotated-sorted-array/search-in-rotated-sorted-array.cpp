#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int t) {

        int start = 0;
        int end = nums.size() - 1;
        int last = nums[nums.size() - 1];

        while (start <= end) {
            int mid = (start + end) / 2;


            if(nums[mid] == t) return mid;
            // subarray 1
            if (nums[mid] >= nums[end]) {
                if (t > nums[mid] || t < nums[start]) {
                    start = mid + 1;
                } else  {
                    end = mid - 1;
                } 
            }
            // subarray 2
            else if (nums[mid] < nums[end]) {
                if (t < nums[mid] || t > nums[end]) {
                    end = mid - 1;
                } else {
                    start = mid + 1;
                }
            } 
        }
        return -1;
    }
};

