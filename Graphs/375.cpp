class Solution {
public:

    int count = 0;

    int findParent(int node, vector<int>& parent) {
        if (parent[node] == node)
            return node;

        return findParent(parent[node], parent);
    }

    void solve(int i, int edgeCount,
               vector<int>& parent,
               vector<vector<int>>& edges,
               int n) {

        // Selected n-1 edges -> valid spanning tree
        if (edgeCount == n - 1) {
            count++;
            return;
        }

        // No edges left
        if (i == edges.size())
            return;

        // Even taking every remaining edge can't give n-1 edges
        if (edgeCount + (edges.size() - i) < n - 1)
            return;

        int u = edges[i][0];
        int v = edges[i][1];

        int pu = findParent(u, parent);
        int pv = findParent(v, parent);

        // TAKE edge
        if (pu != pv) {

            // Save the change
            parent[pv] = pu;

            solve(i + 1, edgeCount + 1,
                  parent, edges, n);

            // BACKTRACK
            parent[pv] = pv;
        }

        // DON'T TAKE edge
        solve(i + 1, edgeCount,
              parent, edges, n);
    }

    int countSpanTree(int n, vector<vector<int>>& edges) {

        count = 0;

        vector<int> parent(n);

        for (int i = 0; i < n; i++)
            parent[i] = i;

        solve(0, 0, parent, edges, n);

        return count;
    }
};