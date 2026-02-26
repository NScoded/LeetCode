class Solution {
public:
    bool containsCycle(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        int total = n * m;
        vector<vector<int>> adj(total);
        
        // Directions
        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, 1, 0, -1};
        
        // 🔹 Build Graph
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                int node = i * m + j;
                
                for(int k = 0; k < 4; k++) {
                    int ni = i + dx[k];
                    int nj = j + dy[k];
                    
                    if(ni >= 0 && nj >= 0 && ni < n && nj < m) {
                        if(grid[ni][nj] == grid[i][j]) {
                            int neighbour = ni * m + nj;
                            adj[node].push_back(neighbour);
                        }
                    }
                }
            }
        }
        
        // 🔹 Cycle Detection (DFS)
        vector<int> vis(total, 0);
        
        function<bool(int,int)> dfs = [&](int node, int parent) {
            vis[node] = 1;
            
            for(int neighbour : adj[node]) {
                if(!vis[neighbour]) {
                    if(dfs(neighbour, node))
                        return true;
                }
                else if(neighbour != parent) {
                    return true;
                }
            }
            return false;
        };
        
        for(int i = 0; i < total; i++) {
            if(!vis[i]) {
                if(dfs(i, -1))
                    return true;
            }
        }
        
        return false;
    }
};