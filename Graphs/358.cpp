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
    
    void dfs(unordered_map<int, list<int>> &adjList,unordered_map<int, bool> &visited,
              vector<int> &ans, int node){
                  
                  ans.push_back(node);
                  visited[node] = true;
                  
                  for(int i: adjList[node]){
                      if(!visited[i]){
                          dfs(adjList,visited,ans,i);
                      }
                  }
                  
              }
  
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        
         unordered_map<int, list<int>> adjList;
        vector<int> ans;
        unordered_map<int, bool> visited;
        
        prepareAdjList(adj,adjList);
        
        dfs(adjList,visited,ans,0);
        
        return ans;
        
    }
};