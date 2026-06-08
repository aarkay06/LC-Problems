class Solution {
public:
    void dfs(int node, int n, vector<vector<int>>& graph, vector<int> arr,
             vector<vector<int>>& res) {

        if (node == n - 1) {
            arr.push_back(node);
            res.push_back(arr);
            return;
        }
       else if (graph[node].size() == 0 ) {
            
                return;
        }
        arr.push_back(node);
        for (int i = 0; i < graph[node].size(); i++) {
            dfs(graph[node][i], n, graph, arr, res);
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> res;
        dfs(0, graph.size(), graph, {}, res);
        return res;
    }
};