class Solution {
	public:
	
	bool dfs(int node, unordered_map<int, list<pair<int, int>>> &adj, vector<bool> &visited, int k, int weight) {
		
		if (weight >= k) {
			return true;
		}
		visited[node] = true;
		
		for (auto nbr: adj[node]) {
			int nbrVal = nbr.first;
			int wt = nbr.second;
			
			if (!visited[nbrVal]) {
				bool ans = dfs(nbrVal, adj, visited, k, weight + wt);
				
				if (ans == true) {
					return true;
				}
			}
		}
		
		visited[node] = false;
		
		return false;
		
	}
	
	bool pathMoreThanK(int V, vector<vector<int>> & edges, int k) {
		// code here
		unordered_map<int, list<pair<int, int>> > adj;
		for (int i = 0; i < edges.size() ; i ++) {
			int u = edges[i][0];
			int v = edges[i][1];
			int w = edges[i][2];
			
			adj[u].push_back({v, w});
			adj[v].push_back({u, w});
		}
		
		vector<bool> visited(V, false);
		return dfs(0, adj, visited, k, 0);
	}
};
