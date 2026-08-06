#include<bits/stdc++.h>

class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        
        unordered_map<int, list<pair<int,int>>> adjList;
        
        //prepare adjList 
        for(int i = 0 ; i < edges.size(); i++){
            
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            
            adjList[u].push_back({v,w});
            adjList[v].push_back({u,w});
        }
        
        vector<int> dist(V,INT_MAX);
        set<pair<int,int>> st;
        
        dist[src] = 0;
        st.insert({dist[src],src});
        
        while(!st.empty()){
            
            auto top = *(st.begin());
            int nodeDistance = top.first;
            int node = top.second;
            st.erase(st.begin());
            
            for(auto neighbour: adjList[node]){
                
                if(nodeDistance + neighbour.second < dist[neighbour.first]){
                    
                    auto record = st.find({dist[neighbour.first],neighbour.first});
                    
                    if(record != st.end()){
                        st.erase(record);
                    }
                    
                    st.insert({nodeDistance + neighbour.second, neighbour.first});
                    dist[neighbour.first] = nodeDistance + neighbour.second;
                    
                }
                
            }
            
        }
        return dist;
        
    }
};