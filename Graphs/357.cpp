class Solution {
  public:
  
    void prepareAdjList(vector<vector<int>> adj, unordered_map<int,list<int>> &adjList){
        
        for(int u = 0;u < adj.size() ;u++){
            for(auto v: adj[u]){
                adjList[u].push_back(v);
                adjList[v].push_back(u);
            }
        }
    }
    
    
    void bfs(unordered_map<int, list<int>> &adjList,unordered_map<int, bool> &visited,
              vector<int> &ans){
                  
                  queue<int> q;
                  visited[0] = 1;
                  q.push(0);
                  
                  
                  while(!q.empty()){
                      int frontNode = q.front();
                      q.pop();
                      
                      ans.push_back(frontNode);
                      
                      //traverse all the nodes connected to front node
                      for(auto n: adjList[frontNode]){
                          if(!visited[n]){
                              q.push(n);
                              visited[n] = 1;
                          }
                      }
                  }
                  
              }
    
  
    vector<int> bfs(vector<vector<int>> &adj) {
        // code here
        unordered_map<int, list<int>> adjList;
        vector<int> ans;
        unordered_map<int, bool> visited;
        
        prepareAdjList(adj,adjList);
        
        bfs(adjList,visited,ans);
        
        
        return ans;
        
    }
};