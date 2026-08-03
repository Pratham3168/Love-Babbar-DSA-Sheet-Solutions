class Solution {
	public:
	
	void prepareAdjlist(int n, int &dest, int &src, unordered_map<int, vector<pair<int, char>>> &adjList, vector<vector<int>> & maze) {
		
		int number = 0;
		vector<vector<int>> id(n, vector<int>(n, -1));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (maze[i][j] == 1)
					id[i][j] = number++;
			}
		}
		src = id[0][0];
		dest = id[n - 1][n - 1];
		
		// preparing adjList
		for (int i = 0 ; i < n; i++) {
			for (int j = 0; j < n; j++) {
				
				if (maze[i][j] == 0)continue;
				
				int u = id[i][j];
				
				// if down exists
				if (i + 1 < n && maze[i + 1][j] == 1) {
					int v = id[i + 1][j];
					adjList[u].push_back({v, 'D'});
					adjList[v].push_back({u, 'U'});
				}
				
				// if right exists
				if (j + 1 < n && maze[i][j + 1] == 1) {
					int v = id[i][j + 1];
					adjList[u].push_back({v, 'R'});
					adjList[v].push_back({u, 'L'});
				}
			}
		}
	}
	
	void dfsMaze(unordered_map<int, vector<pair<int, char>>> &adjList,
	vector<string> &ans, unordered_map<int, bool> &visited,
	int src, int dest, string path)
	{
		
		if (src == dest) {
			ans.push_back(path);
			return;
		}
		
		visited[src] = true;
		for (const auto &neighbour : adjList[src]) {
			
			int val = neighbour.first;
			char dir = neighbour.second;
			
			if (!visited[val]) {
				dfsMaze(adjList, ans, visited, val, dest, path + dir);
			}
		}
		visited[src] = false;
		
	}
	
	vector<string> ratInMaze(vector<vector<int>> & maze) {
		// code here
		int n = maze.size();
		if (maze[0][0] == 0 || maze[n - 1][n - 1] == 0)
			return {};
		
		unordered_map<int, vector<pair<int, char>> > adjList;
		unordered_map<int, bool> visited;
		vector<string> ans;
		
		int src;
		int dest;
		
		// prepare adjList
		prepareAdjlist(n, dest, src, adjList, maze);
		
		// do the dfs
		dfsMaze(adjList, ans, visited, src, dest, "");
		
		sort(ans.begin(), ans.end());
		
		return ans;
	}
};
