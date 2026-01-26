class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>> sol;
        sort(arr.begin(), arr.end());
        int minDiff = arr[1] - arr[0];
        for (int i = 1; i < arr.size(); i++) {
            minDiff = min(arr[i] - arr[i - 1], minDiff);
        }

        for (int i = 1; i < arr.size(); i++) {
            if(arr[i] - arr[i-1] == minDiff){
                sol.push_back({arr[i-1], arr[i]});
            }
        }
        return sol;
    }
};