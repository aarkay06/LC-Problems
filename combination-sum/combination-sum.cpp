class Solution {
public:
    int chosen = false;
     vector<vector<int>> ans;

    void recursion(int i, vector<int>& candidates, vector<int>& res, int target, int sum ){
        if(sum > target || i >= candidates.size()) return;
        if(chosen == true && sum == target){
            ans.push_back(res);
        }

        chosen = true;
        res.push_back(candidates[i]);
        recursion(i, candidates, res, target, sum+candidates[i]);
        res.pop_back();
        chosen= false;
        recursion(i+1, candidates, res, target, sum);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
       
        vector<int> res;  //single combination
        recursion(0, candidates, res, target, 0);

        return ans;

    }
};