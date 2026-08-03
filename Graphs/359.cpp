class Solution {
  public:
  
    bool checkCycleDFS(int i,unordered_map<int,bool> &dfsVisited, unordered_map<int,bool> &visited,
                       unordered_map<int,list<int>> &adjList )
    {
        
        visited[i] = true;
        dfsVisited[i] = true;
        
        for(auto neighbour: adjList[i]){
            
            if(!visited[neighbour]){
                bool checkCycle = checkCycleDFS(neighbour, dfsVisited, visited, adjList);
                if(checkCycle){
                    return true;
                }
            }
            else if(dfsVisited[neighbour] == true){
                return true;
            }
        }
        
        dfsVisited[i] = false;
        return false;
        
    }
  
  
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        unordered_map<int,list<int>> adjList;
        for(int i = 0; i < edges.size() ; i++){
            
            int u = edges[i][0];
            int v = edges[i][1];
            
            adjList[u].push_back(v);
             
        }
        
        unordered_map<int,bool> dfsVisited;
        unordered_map<int,bool> visited;
        
        for(int i = 0; i < V; i++){
            if(!visited[i]){
                bool cycleFound = checkCycleDFS(i,dfsVisited, visited, adjList);
                if(cycleFound){
                    return true;
                }
            }
        }
        
        return false;
    }
};