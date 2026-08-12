class Solution {
  public:
  
    void dfs(int node,vector<bool> &visited,stack<int> &st,unordered_map<int,list<int>> &adjList){
        
        visited[node] = true;
        
        for(int nbr: adjList[node]){
            if(!visited[nbr]){
                dfs(nbr,visited,st,adjList);
            }
        }
        
        st.push(node);
        
    }
    
    
    void revDfs(int node,vector<bool> &visited,stack<int> &st,unordered_map<int,list<int>> &adjList){
        
        visited[node] = true;
        
        for(int nbr: adjList[node]){
            if(!visited[nbr]){
                revDfs(nbr,visited,st,adjList);
            }
        }
    }
    
  
    int kosaraju(int V, vector<vector<int>> &edges) {
        // code here
        unordered_map<int,list<int>> adjList;
        for(int i = 0; i< edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            
            adjList[u].push_back(v);
        }
        
        vector<bool> visited(V,false);
        stack<int> st;
        
        //get the dfs order
        for(int i =0 ; i< V; i ++){
            if(!visited[i]){
                dfs(i,visited,st,adjList);
            }
        }
        
        //transpose the graph
        unordered_map<int,list<int>> transpose;
        for(int i =0 ;i < V; i ++){
            visited[i] = false;
            for(int nbr : adjList[i]){
                transpose[nbr].push_back(i);
            }
        }
        
        //reverse dfs 
        int count =0;
        while(!st.empty()){
            int top = st.top();
            st.pop();
            if(!visited[top]){
                count++;
                revDfs(top,visited,st,transpose);
            }
        }
        
        return count;
    }
};