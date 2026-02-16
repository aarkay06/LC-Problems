class Solution {
public:
    bool isValid(vector<int>& weights, int days, int k) {
        int noOfDays = 1;
        int sum = 0;
        for (int x : weights) {
            if (sum + x <= k) {
                sum += x;
            } else {
                sum = x;
                noOfDays++;
            }
        }
        return noOfDays <= days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int min = *max_element(weights.begin(), weights.end());
        int max = accumulate(weights.begin(), weights.end(), 0);
        int weight;
        while (min <= max) {
            int mid = (min + max) / 2;
            if (isValid(weights, days, mid)) {
                weight = mid;
                max = mid - 1;
            } else {
                min = mid + 1;
            }
        }
        return weight;
    }
};