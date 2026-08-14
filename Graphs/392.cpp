class Solution {
	public:
	
	bool isSafe(int c, int node, unordered_map<int, list<int>> &adj, vector<int> &color) {
		
		for (auto nbr : adj[node]) {
			if (color[nbr] == c) {
				return false;
			}
		}
		return true;
		
	}
	
	bool solve(int node, vector<int> &color, unordered_map<int, list<int>> &adj, int m,int v) {
	    
	    if(node == v){
	        return true;
	    }
		
		for (int c = 1; c <= m; c++) {
			
			if (isSafe(c, node, adj, color)) {
				
				color[node] = c;
				
				if (solve(node + 1, color, adj, m, v)) {
					return true;
				}
				
				color[node] = 0;
				
			}
			
		}
		return false;
		
	}
	
	bool graphColoring(int v, vector<vector<int>> &edges, int m) {
		// code here
		unordered_map<int, list<int>> adj;
		for (int i = 0; i<edges.size(); i++) {
			
			int u = edges[i][0];
			int v = edges[i][1];
			adj[u].push_back(v);
			adj[v].push_back(u);
			
		}
		
		vector<int> color(v, 0);
		
		return solve(0, color, adj, m,v);
		
	}
};
