class Solution {
public:
    bool isValid(vector<int>& arr, int mid, int k) {
        int s = 0, group = 1;
        for (int v : arr) {
            if (s + v <= mid)
                s += v;
            else {
                s = v;
                group++;
            }
        }
        return group <= k;
    }

    int splitArray(vector<int>& arr, int k) {
        int s = *max_element(arr.begin(), arr.end());
        int e = accumulate(arr.begin(), arr.end(), 0);
        int ans = 0;
        while (s <= e) {
            int mid = s + (e - s) / 2;
            if (isValid(arr, mid, k)) {
                ans = mid;
                e = mid - 1;
            } else
                s = mid + 1;
        }
        return ans;
    }
};