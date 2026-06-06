class Solution {
public:
    void bfs(int node, vector<vector<int>>& adj, vector<int>& visited) {
        // code here
        queue<int> q;
        q.push(node);
        visited[node] = 1;
        while (!q.empty()) {
            int k = q.front();
            q.pop();

            for (int i = 0; i < visited.size(); i++) {
                if (adj[k][i] == 1 && !visited[i]) {
                    q.push(i);
                    visited[i] = 1;
                }
            }
        }

    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<int> visited(isConnected.size());
        int count = 0;
        for (int i = 0; i < visited.size(); i++) {
            if (!visited[i]) {
                count++;
                bfs(i, isConnected, visited);
            }
        }
        return count;
    }
};