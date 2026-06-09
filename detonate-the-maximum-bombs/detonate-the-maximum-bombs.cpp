class Solution {
public:
    int dfs(int bomb, int source,  vector<vector<int>>& graph, vector<vector<int>>& bombs, vector<vector<int>> &visited) {
        if (bomb < 0 || bomb >= graph.size() || visited[source][bomb] == 1) {
            return 0;
        }

        visited[source][bomb] =1;
        int count = 1;
        for (int i = 0; i < graph[bomb].size(); i++) {
            count += dfs(graph[bomb][i],source, graph, bombs, visited);
        }
        return count;
    }

    int maximumDetonation(vector<vector<int>>& bombs) {
        vector<vector<int>> graph(bombs.size(), vector<int>(0));
        vector<vector<int>> visited(bombs.size(), vector<int>(graph.size()));
        int count = 0;
        for (int i = 0; i < bombs.size(); i++) {
            int x1 = bombs[i][0];
            int y1 = bombs[i][1];
            int r = bombs[i][2];

            for (int j = 0; j < bombs.size(); j++) {
                int x2 = bombs[j][0];
                int y2 = bombs[j][1];
                long long dx = x1 - x2;
                long long dy = y1 - y2;

                if (dx * dx + dy * dy <= 1LL * r * r) {
                    graph[i].push_back(j);
                }
            }
        }
        for (int i = 0; i < bombs.size(); i++) {
            count = max(count, dfs(i,i, graph, bombs, visited));
        }
        return count;
    }
};