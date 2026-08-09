class Solution {
public:

    void makeSet(vector<int>& parent, vector<int>& rank, int n) {
        for(int i = 0; i < n; i++) {
            parent[i] = i;
            rank[i] = 0;
        }
    }

    int findParent(vector<int>& parent, int node) {
        if(parent[node] == node)
            return node;

        return parent[node] = findParent(parent, parent[node]);
    }

    void unionSet(int u, int v, vector<int>& parent, vector<int>& rank) {

        u = findParent(parent, u);
        v = findParent(parent, v);

        if(rank[u] < rank[v]) {
            parent[u] = v;
        }
        else if(rank[u] > rank[v]) {
            parent[v] = u;
        }
        else {
            parent[v] = u;
            rank[u]++;
        }
    }

    int kruskalsMST(int V, vector<vector<int>>& edges) {

        // Sort edges according to weight
        sort(edges.begin(), edges.end(),
             [](vector<int>& a, vector<int>& b) {
                 return a[2] < b[2];
             });

        vector<int> parent(V);
        vector<int> rank(V);

        makeSet(parent, rank, V);

        int minWeight = 0;

        for(auto edge : edges) {

            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            int uParent = findParent(parent, u);
            int vParent = findParent(parent, v);

            // Different components -> include edge
            if(uParent != vParent) {

                minWeight += w;

                unionSet(u, v, parent, rank);
            }
        }

        return minWeight;
    }
};