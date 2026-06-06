# Problem: BFS of a graph

## Problem Information
- **Platform:** Geeksforgeeks
- **Difficulty:** Easy
- **URL:** https://www.geeksforgeeks.org/problems/bfs-traversal-of-graph/1
- **Date:** 2026-06-06

## Solution

```cpp
class Solution {
  public:
    vector<int> bfs(vector<vector<int>> &adj) {
        // code here
        queue<int> q;
        q.push(0);
        vector<int> visited(adj.size());
        vector<int> bfs;
        visited[0]=1;
        while(!q.empty()){
            int k = q.front();
            q.pop();
            for(auto it: adj[k]){
                if(!visited[it])
               { q.push(it);
                   visited[it] = 1;
               }
            }
            bfs.push_back(k);
        }
        return bfs;
    }
};
```

---
*Generated automatically by LeetFeedback Extension*
