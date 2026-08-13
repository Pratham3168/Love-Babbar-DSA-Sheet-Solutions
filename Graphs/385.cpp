class Solution {
	public:
	
	void topoSort(unordered_map<int, list<pair<int,int>>> &adjList, stack<int> &st, unordered_map<int, bool> &visited, int node) {
		
		visited[node] = true;
		
		for (auto neighbour: adjList[node]) {
			if (!visited[neighbour.first]) {
				topoSort(adjList, st, visited, neighbour.first);
			}
		}
		
		st.push(node);
		
	}
	
	vector<int> maxDistance(int V, int src, vector<vector<int>> &edges) {
		// code here
		unordered_map<int, list<pair<int,int>>> adjList;
		
		for (int i = 0 ; i < edges.size() ; i++) {
			
			int u = edges[i][0];
			int v = edges[i][1];
			int w = edges[i][2];
			
			adjList[u].push_back({v,w});
			
		}
		
		unordered_map<int, bool> visited;
		stack<int> st;
		
		for (int i = 0 ; i < V; i++) {
			if (!visited[i]) {
				topoSort(adjList, st, visited, i);
			}
		}
		
		vector<int> ans; //topological sort
		while (!st.empty()) {
			ans.push_back(st.top());
			st.pop();
		}
		
		vector<int> dist(V,INT_MIN);
		dist[src] = 0;
		
		for (int node : ans) {
			
			if (dist[node] == INT_MIN)
				continue;
			
			for (auto nbr : adjList[node]) {
				
				int nextNode = nbr.first;
				int weight = nbr.second;
				
				dist[nextNode] =
				max(dist[nextNode], dist[node] + weight);
			}
		}
		return dist;
	}
};
