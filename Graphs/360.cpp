class Solution {
	public:
	
	void prepareAdjList(vector<vector<int>> edges, unordered_map<int, list<int>> &adjList) {
		
		for (int i = 0 ; i<edges.size() ; i++) {
			
			int u = edges[i][0];
			int v = edges[i][1];
			
			adjList[u].push_back(v);
			adjList[v].push_back(u);
			
		}
	}
	
	bool isCyclicBFS(int src,unordered_map<int, bool> &visited, unordered_map<int, list<int>> &adjList) {
		
		queue<int> q;
		unordered_map<int, int> parent;
		auto it = adjList.begin();
		visited[src] = true;
		parent[src]=-1;
		q.push(src);
		
		while (!q.empty()) {
			
			int front = q.front();
			q.pop();
			
			for (auto neighbour: adjList[front]) {
				if (visited[neighbour] == true && parent[front] != neighbour) {
					return true;
				}
				else if (!visited[neighbour]) {
					q.push(neighbour);
					parent[neighbour] = front;
					visited[neighbour] = true;
				}
			}
			
		}
		return false;
	}
	
	bool isCyclicDFS(int node, int parent,unordered_map<int, bool> &visited, unordered_map<int, list<int>> &adjList){
	    
	    visited[node] = true;
	    
	    for(auto neighbour: adjList[node]){
	        
	        if(!visited[neighbour]){
	            bool isCyclic = isCyclicDFS(neighbour,node,visited,adjList);
	            if(isCyclic)return true;
	        }
	        else if(neighbour != parent){
	            return true;
	        }
	        
	    }
	    return false;
	}

	
	bool isCycle(int V, vector<vector<int>> & edges) {
		// Code here
		
		unordered_map<int, list<int>> adjList;
		unordered_map<int, bool> visited;
		
		prepareAdjList(edges, adjList);
		
		for(int i = 0; i < V; i++){
        if(!visited[i]){
            
            
            // if(isCyclicBFS(i, visited, adjList))
            //     return true;
            
            if(isCyclicDFS(i,-1,visited,adjList)){
                return true;
            }
        }
    }
		

		return false ;
		
	}
};
