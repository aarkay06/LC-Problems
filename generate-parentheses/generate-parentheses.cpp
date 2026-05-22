class Solution {
public:
    // i for number of left bracket '('
    void recursion(int index, vector<string>& res, string& str, int n, int i) {
        
        if (index >= n) {
            if (i == 0)
                res.push_back(str);
            return;
        }

        if (i > 0) {
            str.append("(");
            recursion(index + 1, res, str, n, i + 1);
            str.pop_back();
            str.append(")");
            recursion(index + 1, res, str, n, i - 1);
            str.pop_back();
        }else{
            str.append("(");
            recursion(index + 1, res, str, n, i + 1);
            str.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string str = "";
        recursion(0, res, str, n * 2, 0);
        return res;
    }
};