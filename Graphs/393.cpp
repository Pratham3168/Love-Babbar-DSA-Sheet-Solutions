class Solution {
  public:
    int minimumEdgeReversal(vector<vector<int>> &edges, int n, int src, int dst) {
        // code here  
        unordered_map<int,list<pair<int,int>>> adj;
        //preparing a bidirectional cost graph
        for(int i= 0; i< edges.size() ;i++){
            int u = edges[i][0];
            int v = edges[i][1];
            
            adj[u].push_back({v,0});
            adj[v].push_back({u,1});
        }
        
        vector<int> dist(n+1,INT_MAX);
        set<pair<int,int>> st;
        
        dist[src] = 0;
        st.insert({0,src});
        
         while(!st.empty()){
            
            auto top = *(st.begin());
            st.erase(st.begin());

            int nodeDistance = top.first;
            int node = top.second;
            
            for(auto neighbour: adj[node]){
                
                int nbr = neighbour.first;
                int weight = neighbour.second;

                if(nodeDistance + weight < dist[nbr]) {

                    // Remove old pair
                    if(dist[nbr] != INT_MAX) {
                        st.erase({dist[nbr], nbr});
                    }

                    // Update distance
                    dist[nbr] = nodeDistance + weight;

                    // Insert new pair
                    st.insert({dist[nbr], nbr});
                }
                
            }
            
        }
        if(dist[dst] == INT_MAX)
            return -1;

        return dist[dst];
    }
};