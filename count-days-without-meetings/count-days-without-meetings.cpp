class Solution {
public:

    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        vector<vector<int>> res;
        sort(intervals.begin(), intervals.end());

        res.push_back(intervals[0]);

        for (int i = 1; i < intervals.size(); i++) {
            int a = res[res.size() - 1][0];
            int b = res[res.size() - 1][1];
            int c = intervals[i][0];
            int d = intervals[i][1];

            if (c <= b ) {
                vector<int> arr(2);
                arr[0] = a;
                arr[1] = max(b, d);
                res.pop_back();
                res.push_back(arr);
            } else{
                res.push_back({c,d});
            }
        }

        return res;
    }

    int countDays(int days, vector<vector<int>>& meetings) {
        vector<vector<int>> meets = merge(meetings);

        int free = 0;
        int last = 0;

        for (int i = 0; i < meets.size(); i++) {
              int j = meets[i][0];
              int k = meets[i][1];
              free+= (j- last-1);
              last =k;
        }
         free+= (days- last);
        return free;
    }
};