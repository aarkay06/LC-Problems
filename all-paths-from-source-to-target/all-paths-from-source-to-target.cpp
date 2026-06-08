class Solution {
public:
    void dfs(int node, int n, vector<vector<int>>& graph, vector<int>& arr,
             vector<vector<int>>& res) {

        if (node == n - 1) {
            arr.push_back(node);
            res.push_back(arr);
            arr.pop_back();
            return;
        }

        arr.push_back(node);
        for (int i = 0; i < graph[node].size(); i++) {
            dfs(graph[node][i], n, graph, arr, res);
        }
        arr.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> res;
        vector<int> arr;
        dfs(0, graph.size(), graph,arr, res);
        return res;
    }
};