class Solution {
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        unordered_map<int, list<int>> adjList;
        for(int i = 0; i< edges.size() ; i++){
            
            int u = edges[i][0];
            int v = edges[i][1];
            
            adjList[u].push_back(v);
        }
        
        vector<int> indegree(V);
        for(auto i : adjList){
            for(auto j : i.second){
                indegree[j]++;
            }
        }
        
        vector<int> ans;
        queue<int> q;
        //0 indegree walo ko push krdo
        for(int i = 0 ; i < indegree.size() ;i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        
        //do bfs
        while(!q.empty()){
            
            int front = q.front();
            q.pop();
            
            ans.push_back(front);
            for(auto neighbours : adjList[front]){
                indegree[neighbours]--;
                
                if(indegree[neighbours] == 0){
                    q.push(neighbours);
                }
            }
            
            
        }
        return ans;
        
    }
};