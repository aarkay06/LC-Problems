class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals,
                               vector<int>& newInterval) {
        if (intervals.size() == 0)
            return {newInterval};

        bool added = 0;

        vector<vector<int>> res;
        int c = intervals[0][0];
        int d = intervals[0][1];

        int e = newInterval[0];
        int f = newInterval[1];

        if ((e <= d) && f >= c) {
            c = min(c, e);
            d = max(d, f);
            added = 1;
        }

        if (f < c)
            res.push_back({e, f});

        res.push_back({c, d});

        for (int i = 1; i < intervals.size(); i++) {
            int a = res[res.size() - 1][0];
            int b = res[res.size() - 1][1];
            int c = intervals[i][0];
            int d = intervals[i][1];

            int e = newInterval[0];
            int f = newInterval[1];

            if (e <= d && f >= c) {
                c = min(c, e);
                d = max(d, f);
                added = 1;
            }
            if (f < c && e > b)
                res.push_back({e, f});

            if (c <= b) {
                vector<int> arr(2);
                arr[0] = a;
                arr[1] = max(b, d);
                res.pop_back();
                res.push_back(arr);
            } else {
                res.push_back({c, d});
            }
        }

        if (!added && res[res.size() - 1][1] < newInterval[1])
            res.push_back({newInterval[0], newInterval[1]});

        return res;
    }
};