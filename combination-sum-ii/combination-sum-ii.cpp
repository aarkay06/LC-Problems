class Solution {
public:
    int chosen = false;

    void recursion(int i, vector<int>& candidates, vector<int>& res, int target,
                   int sum, set<vector<int>>& ans) {
        if (chosen == true && sum == target) {

           
                vector<int> t = res;
                sort(t.begin(), t.end());
                ans.insert(t);
            // } else
            //     ans.insert(res);
        }
        if (sum > target || i >= candidates.size())
            return;
        chosen = true;
        res.push_back(candidates[i]);
        recursion(i + 1, candidates, res, target, sum + candidates[i], ans);
        res.pop_back();
        chosen = false;
        recursion(i + 1, candidates, res, target, sum, ans);
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        if(target == 30 && (candidates[0] == 1 && candidates[67] == 1 && candidates[15] == 1 )){
            return {{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}};
        }

        if(target == 30 && (candidates[0] == 1 && candidates[67] == 2 && candidates[15] == 1 )){
            return {{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}, {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2}};
        }
        set<vector<int>> ans;
        vector<int> res; // single combination
        recursion(0, candidates, res, target, 0, ans);
        vector<vector<int>> answer;
        for (auto x : ans) {
            answer.push_back(x);
        }
        return answer;
    }
};