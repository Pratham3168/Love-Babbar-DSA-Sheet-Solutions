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
  
    bool canFinish(int n, vector<vector<int>>& pre) {
        // Code here
        unordered_map<int,list<int>> adjList;
        for(int i = 0; i < pre.size() ; i++){
            
            int u = pre[i][0];
            int v = pre[i][1];
            
            adjList[v].push_back(u);
             
        }
        
        unordered_map<int,bool> dfsVisited;
        unordered_map<int,bool> visited;
        
        for(int i = 0; i < n; i++){
            if(!visited[i]){
                bool cycleFound = checkCycleDFS(i,dfsVisited, visited, adjList);
                if(cycleFound){
                    return false;
                }
            }
        }
        
        return true;
    }
};