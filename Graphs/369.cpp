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
    
    void find_time(vector<int> &time_ans,unordered_map<int, list<int>> &adjList,
                   vector<int> &topoOrder)
    {
        
        for(int node: topoOrder){
            
            for(int neighbour: adjList[node]){
                time_ans[neighbour-1] = max(time_ans[node-1]+1, time_ans[neighbour-1]);
            }
            
        }
        
    }
  
    vector<int> minTime(int V, vector<vector<int>> &edges) {
        // code here
        unordered_map<int, list<int>> adjList;
        for(int i = 0 ; i < edges.size() ; i++){
            
            int u = edges[i][0];
            int v = edges[i][1];
            
            adjList[u].push_back(v);
            
        }
        
        unordered_map<int,bool> visited;
        stack<int> st;
        
        for(int i = 1 ; i <= V; i++){
            if(!visited[i]){
                topoSort(adjList,st,visited,i);
            }
        }
        
        vector<int> topoOrder;
        while(!st.empty()){
            
            topoOrder.push_back(st.top());
            st.pop();
            
        }
        
        vector<int> time_ans(V,1);
        
        find_time(time_ans, adjList, topoOrder);
        
        return time_ans;
        
        
    }
};