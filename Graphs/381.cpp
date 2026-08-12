/*
    ------------------------------------------------------------
                    BRIDGE EDGE IN A GRAPH
    ------------------------------------------------------------

    APPROACH 2: TARJAN'S ALGORITHM

    Tarjan's algorithm finds bridges using DFS.

    For every node we maintain:

    1. disc[node]
       -> Discovery time of the node in DFS.

    2. low[node]
       -> Lowest discovery time that can be reached from
          this node using DFS tree edges and at most one
          back edge.

    Initially:

        disc[node] = low[node] = timer++;

    For a back edge:

        low[node] = min(low[node], disc[neighbour]);

    After visiting a DFS child:

        low[node] = min(low[node], low[child]);


    BRIDGE CONDITION:

        if(low[child] > disc[node])

    then:

        node ---- child

    is a bridge.

    Why?

    If low[child] > disc[node], then the subtree of child
    cannot reach node or any ancestor of node using another
    path.

    Therefore, removing node-child will disconnect the graph.


    Time Complexity  : O(V + E)
    Space Complexity : O(V + E)
*/

class Solution {
public:

    void dfs(int node,
             int parent,
             unordered_map<int, list<int>> &adj,
             vector<int> &disc,
             vector<int> &low,
             vector<bool> &visited,
             int &timer,
             int c,
             int d,
             bool &ans) {

        // Mark node as visited
        visited[node] = true;

        // Discovery time and lowest time
        disc[node] = low[node] = timer++;


        for(int neighbour : adj[node]) {

            // Don't go back through the same edge
            // from which we came
            if(neighbour == parent) {
                continue;
            }


            // Back edge
            if(visited[neighbour]) {

                low[node] = min(low[node],
                                disc[neighbour]);
            }


            // DFS tree edge
            else {

                dfs(neighbour,
                    node,
                    adj,
                    disc,
                    low,
                    visited,
                    timer,
                    c,
                    d,
                    ans);


                // Update low value after DFS
                low[node] = min(low[node],
                                 low[neighbour]);


                // Bridge condition
                if(low[neighbour] > disc[node]) {

                    // Check whether this is the given edge
                    if((node == c && neighbour == d) ||
                       (node == d && neighbour == c)) {

                        ans = true;
                    }
                }
            }
        }
    }


    bool isBridge(int V, vector<vector<int>> &edges, int c, int d) {

        // Create adjacency list
        unordered_map<int, list<int>> adj;

        for(int i = 0; i < edges.size(); i++) {

            int u = edges[i][0];
            int v = edges[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }


        // Discovery time
        vector<int> disc(V, -1);

        // Lowest discovery time reachable
        vector<int> low(V, -1);

        // Visited array
        vector<bool> visited(V, false);


        int timer = 0;

        bool ans = false;


        // Graph may be disconnected,
        // so run DFS for every component
        for(int i = 0; i < V; i++) {

            if(!visited[i]) {

                dfs(i,
                    -1,
                    adj,
                    disc,
                    low,
                    visited,
                    timer,
                    c,
                    d,
                    ans);
            }
        }


        return ans;
    }
};











/*
    ------------------------------------------------------------
                    BRIDGE EDGE IN A GRAPH
    ------------------------------------------------------------

    APPROACH 1: Remove the given edge and check connectivity

    An edge (c, d) is a bridge if removing it disconnects
    c from d.

    Steps:
    1. Create the adjacency list.
    2. Ignore/remove the given edge (c, d).
    3. Run DFS from c.
    4. Check whether d is reachable from c.
       - If d is reachable -> another path exists -> NOT a bridge.
       - If d is not reachable -> no alternate path -> BRIDGE.

    Time Complexity  : O(V + E)
    Space Complexity : O(V + E)
*/

class Solution {
public:

    bool dfs(unordered_map<int, list<int>> &adjList,
             int node,
             int d,
             vector<bool> &visited) {

        // Destination reached
        if(node == d) {
            return true;
        }

        visited[node] = true;

        for(int neighbour : adjList[node]) {

            if(!visited[neighbour]) {

                if(dfs(adjList, neighbour, d, visited)) {
                    return true;
                }
            }
        }

        // d is not reachable from this node
        return false;
    }


    bool isBridge(int V, vector<vector<int>> &edges, int c, int d) {

        // Create adjacency list
        unordered_map<int, list<int>> adjList;

        for(int i = 0; i < edges.size(); i++) {

            int u = edges[i][0];
            int v = edges[i][1];

            // Remove the given edge (c, d)
            if((u == c && v == d) ||
               (u == d && v == c)) {

                continue;
            }

            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }


        vector<bool> visited(V, false);

        // Check whether d is still reachable from c
        bool reachable = dfs(adjList, c, d, visited);

        // If d is not reachable, then (c,d) is a bridge
        return !reachable;
    }
};