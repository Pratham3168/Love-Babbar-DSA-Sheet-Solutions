class Solution {
  public:
  
    void prepareAdjList(int n, vector<int> &dx, vector<int> &dy,
                        vector<vector<int>> &adjList)
    {
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                
                int u = i * n + j;
                
                for(int k = 0 ; k < 8 ; k++){
                    
                    int newX = i + dx[k];
                    int newY = j + dy[k];
                    
                    if(newX >= 0 && newX < n &&
                       newY >= 0 && newY < n){
                        
                        int v = newX * n + newY;
                        adjList[u].push_back(v);
                    }
                }
            }
        }
    }
    
    
    int knightBFS(vector<vector<int>> &adjList, int src, int dest, int n){
        
        queue<int> q;
        vector<int> dist(n * n, -1);
        
        q.push(src);
        dist[src] = 0;
        
        while(!q.empty()){
            
            int frontNode = q.front();
            q.pop();
            
            if(frontNode == dest)
                return dist[frontNode];
            
            for(int neighbour : adjList[frontNode]){
                
                if(dist[neighbour] == -1){
                    
                    dist[neighbour] = dist[frontNode] + 1;
                    q.push(neighbour);
                }
            }
        }
        
        return -1;
    }
  
  
    int minStepToReachTarget(vector<int>& knightPos,
                             vector<int>& targetPos,
                             int n) {
        
        vector<vector<int>> adjList(n * n);
        
        vector<int> dx = {-2,-2,-1,-1,1,1,2,2};
        vector<int> dy = {-1,1,-2,2,-2,2,-1,1};
        
        // Prepare adjacency list
        prepareAdjList(n, dx, dy, adjList);
        
        // Convert 1-based to 0-based
        int sx = knightPos[0] - 1;
        int sy = knightPos[1] - 1;
        
        int tx = targetPos[0] - 1;
        int ty = targetPos[1] - 1;
        
        int src = sx * n + sy;
        int dest = tx * n + ty;
        
        return knightBFS(adjList, src, dest, n);
    }
};