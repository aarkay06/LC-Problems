class Solution {
public:
    void helper(int index, string& digits, string& res, vector<string>& ans,
                int i) {
        res.push_back('a' + ((digits[index] - '0') - 2) * 3 + i);
        recursion(index + 1, digits, res, ans);
        res.pop_back();
        res.push_back('a' + ((digits[index] - '0') - 2) * 3 + 1 + i);
        recursion(index + 1, digits, res, ans);
        res.pop_back();
        res.push_back('a' + ((digits[index] - '0') - 2) * 3 + 2 + i);
        recursion(index + 1, digits, res, ans);
        res.pop_back();
    }

    void recursion(int index, string& digits, string& res,
                   vector<string>& ans) {
        if (index >= digits.size()) {
            ans.push_back(res);
            return;
        }else{

        

        if (digits[index] - '0' >= 7) {
            if (digits[index] - '0' == 7) {
                helper(index, digits, res, ans, 0);
                res.push_back('a' + ((digits[index] - '0') - 2) * 3 +3);
                recursion(index + 1, digits, res, ans);
                res.pop_back();
            } else if (digits[index] - '0' == 8) {
                helper(index, digits, res, ans, 1);
            } else {
                helper(index , digits, res, ans, 1);
                res.push_back('a' + ((digits[index] - '0') - 2) * 3 + 4);
                recursion(index + 1, digits, res, ans);
                res.pop_back();
            }
        } else {
            helper(index, digits, res, ans, 0);
        }}
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        string res;
        recursion(0, digits, res, ans);
        return ans;
    }
};