class Solution {
public:
    bool bfs(int node, vector<vector<int>>& graph, queue<pair<int, int>>& q,
             vector<int>& visited) {

        q.push({node, 1});
        visited[node] = 1;

        while (!q.empty()) {
            auto [node, s] = q.front();
            q.pop();
            // if (s == 1) {
            //     if (visited[node] == 2)
            //         return false;
            //     visited[node] = 1;
            // }

            // if (s == 2) {
            //     if (visited[node] == 1)
            //         return false;
            //     visited[node] = 2;
            // }

            // if(graph[node].size() == 0) return false;

            for (int i = 0; i < graph[node].size(); i++) {
                if (!visited[graph[node][i]]) {
                    q.push({graph[node][i], 3 - s});
                    visited[graph[node][i]] = 3 -s;
                } else if (visited[graph[node][i]] ==  s) {
                    return false;
                }
            }
        }

        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> visited(graph.size());
        queue<pair<int, int>> q;
        for (int i = 0; i < graph.size(); i++) {
            if (!visited[i] && graph[i].size() > 0) {
                bool a = bfs(i, graph, q, visited);
                if (a == false)
                    return false;
            }
        }
        return true;
    }
};