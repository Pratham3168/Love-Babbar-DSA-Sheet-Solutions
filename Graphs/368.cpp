class Solution {
  public:
  
    void topoSort(unordered_map<int, list<int>> &adjList, stack<int> &st,unordered_map<int,bool> &visited,int node){
        
        visited[node] = true;
        
        for(auto neighbour: adjList[node]){
            if(!visited[neighbour]){
                topoSort(adjList,st,visited,neighbour);
            }
        }
        
        st.push(node);
        
    }
  
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        
        unordered_map<int, list<int>> adjList;
        
        for(int i = 0 ; i < edges.size() ; i++){
            
            int u = edges[i][0];
            int v = edges[i][1];
            
            adjList[u].push_back(v);
            
        }
        
        unordered_map<int,bool> visited;
        stack<int> st;
        
        for(int i = 0 ; i < V; i++){
            if(!visited[i]){
                topoSort(adjList,st,visited,i);
            }
        }
        
        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        
        return ans;
    }
};