class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        // code here
        unordered_map<int, list<pair<int,int>>> adjList;
        for(int i = 0; i < edges.size() ; i++){
            
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            
            adjList[u].push_back({v,w});
            adjList[v].push_back({u,w});
            
        }
        
        vector<int> key(V,INT_MAX);
        vector<int> parent(V,-1);
        vector<bool> mst(V,false);
        
        key[0] = 0;
        parent[0]=-1;
        
        for(int i = 0 ;i < V; i++){
            
            int mini = INT_MAX;
            int u;
            for(int k = 0; k < V;k++){
                if( mst[k] == false && key[k] < mini){
                    u=k;
                    mini = key[k];
                }
            }
            
            mst[u] = true;
            for(auto node: adjList[u]){
                
                int v = node.first;
                int w = node.second;
                
                if( mst[v] == false && w < key[v]){
                    key[v] = w;
                    parent[v] = u;
                }
            }
        }
        int sum =0;
        
        for(int ele: key){
            sum += ele;
        }
        
        return sum;
        
    }
};