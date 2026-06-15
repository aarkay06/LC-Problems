class Solution {
public:
    // void dfs(int node,int index, int source, vector<int>& edges,vector<int>&
    // visited, int &cycle) {
    //     if (edges[node] == -1)
    //         return;
    //     if (visited[node] == 1){
    //         if(visited[node] != source) return;
    //      cycle = max(cycle, index);
    //      return;
    //     }

    //     visited[node] = 1;
    //     dfs(edges[node], index+1, source,  edges, visited, cycle);
    //     visited[node] = 0;
    // }

    int bfs(int node, vector<int>& edges, vector<pair<int, int>> & visited) {
        queue<int> q;
        q.push(node);

        // vector<int> mp(edges.size());
        // unordered_map<int, int> mp;
        int count = 0;
        while (!q.empty()) {
            int n = q.front();
            q.pop();
            if (edges[n] == -1){
                visited[n] = {node, count};
                return -1;}
           
            auto [i, j] = visited[n];
            if(i == node){
                return count - j;
            }
            else if (i != -1) return -1;

            visited[n] = {node, count};
            q.push(edges[n]);
            count++;
        }
        return -1;
    }

    int longestCycle(vector<int>& edges) {
        vector<pair<int, int>> visited(edges.size(), {-1,-1});
        int maxC = -1;
        for (int i = 0; i < edges.size(); i++) {
            if (visited[i].second == -1) {
                maxC = max(maxC, bfs(i, edges, visited));
            }
        }
        return maxC;
    }
};