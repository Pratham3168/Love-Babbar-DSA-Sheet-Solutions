class Solution {
public:

    void dfs(int node, unordered_map<int, list<int>> &adj, vector<int> &visited) {
        visited[node] = 1;

        for (auto neighbour : adj[node]) {
            if (!visited[neighbour]) {
                dfs(neighbour, adj, visited);
            }
        }
    }

    int makeConnected(int n, vector<vector<int>>& connections) {

        // Not enough cables to connect all computers
        if (connections.size() < n - 1)
            return -1;

        unordered_map<int, list<int>> adj;

        // Build adjacency list
        for (auto &edge : connections) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> visited(n, 0);

        int components = 0;

        // Count connected components
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                components++;
                dfs(i, adj, visited);
            }
        }

        // Minimum operations required
        return components - 1;
    }
};