class Solution {
  public:
  
    bool dfs(int node,vector<int> &color,unordered_map<int,list<int>> &adjList){
        
        for(int nbr: adjList[node]){
            if(color[nbr] == -1){
                color[nbr] = 1 - color[node];
                bool ans = dfs(nbr,color,adjList);
                if(ans == false){return false;}
            }
            else if(color[nbr] == color[node]){
                return false;
            }
        }
        return true;
    }
  
    bool isBipartite(int V, vector<vector<int>> &edges) {
        // Code here
        unordered_map<int,list<int>> adjList;
        for(int i = 0; i < edges.size() ;i++){
            
            int u = edges[i][0];
            int v = edges[i][1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
            
        }
        
        vector<int> color(V,-1);//-1 indicated not colored or not visited
        for(int i =0; i< V; i++){
            if(color[i] == -1){
                color[i] = 1;
                bool ans = dfs(i,color,adjList);
                if(ans == false){
                    return false;
                }
            }
        }
        return true;
    }
};