class Solution {
public:
    bool bfs(int source, int dest, vector<vector<int>>& adj,
             vector<int> visited) {

        queue<int> q;
        q.push(source);

        while (!q.empty()) {
            int i = q.front();
            q.pop();
            for (int j = 0; j < adj[i].size(); j++) {
                int el = adj[i][j];
                if (el == dest)
                    return true;

                if (!visited[el]) {
                    visited[el] = 1;
                    q.push(el);
                }
            }
        }

        return false;
    }

    bool validPath(int n, vector<vector<int>>& edges, int source,
                   int destination) {
                    if(source == destination ) return true;
        vector<int> visited(n);
        vector<vector<int>> adj(n);

        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        visited[source] = 1;

        return bfs(source, destination, adj, visited);
    }
};