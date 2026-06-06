# DFS of Graph

## Problem Information
- **Platform:** Geeksforgeeks
- **Difficulty:** Easy
- **URL:** https://www.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1
- **Date:** 2026-06-06

## Solution

```cpp
class Solution {
    public:
    void read(vector<vector<int>> & adj, vector<int>& dfsA, vector<int>& visited, int node) {
        dfsA.push_back(node);
        visited[node] = 1;
        for (auto i: adj[node]) {
            if (!visited[i]) {
                read(adj, dfsA, visited, i);
            }
        }
    }
    vector<int> dfs(vector<vector<int>> & adj) {
        vector<int> dfsA;
        vector<int> visited(adj.size());
        visited[0] = 1;
        int node = 0;
        read(adj, dfsA, visited, 0);
        return dfsA;
    }
};
```

---
*Generated automatically by LeetFeedback Extension*
