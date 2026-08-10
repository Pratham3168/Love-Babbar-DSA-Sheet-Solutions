/*
============================================================
              BELLMAN-FORD ALGORITHM
============================================================

Bellman-Ford is used for:
1. Finding shortest distances from a fixed source
   → dist[source] = 0, rest = INF

2. Detecting a negative weight cycle reachable from
   a fixed source
   → Relax V-1 times, then check one extra time

3. Detecting a negative weight cycle anywhere in the graph
   → Initialize dist[] = 0 for all vertices
   → This allows every vertex/component to participate

IMPORTANT:
- V-1 relaxations are enough for shortest paths
  without a negative cycle.
- If an edge can still be relaxed on the Vth iteration,
  a negative weight cycle exists.

------------------------------------------------------------
Variations:
------------------------------------------------------------

Fixed source:
    vector<int> dist(V, 1e9);
    dist[src] = 0;

Negative cycle anywhere:
    vector<int> dist(V, 0);

------------------------------------------------------------
Time Complexity:
    O(V * E)

Space Complexity:
    O(V)

------------------------------------------------------------
*/



// ============================================================
// 1. FIXED SOURCE → FIND SHORTEST DISTANCE ARRAY
// ============================================================

vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {

    vector<int> dist(V, 1e9);
    dist[src] = 0;

    // Relax all edges V-1 times
    for(int i = 0; i < V-1; i++) {

        for(auto edge : edges) {

            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            if(dist[u] != 1e9 && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }

    return dist;
}






// ============================================================
// 2. FIXED SOURCE → CHECK NEGATIVE CYCLE
//    Checks negative cycle reachable from src
// ============================================================

bool hasNegativeCycle(int V, vector<vector<int>>& edges, int src) {

    vector<int> dist(V, 1e9);
    dist[src] = 0;

    // Relax V-1 times
    for(int i = 0; i < V-1; i++) {

        for(auto edge : edges) {

            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            if(dist[u] != 1e9 && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }

    // Vth relaxation
    // If distance still decreases → negative cycle
    for(auto edge : edges) {

        int u = edge[0];
        int v = edge[1];
        int w = edge[2];

        if(dist[u] != 1e9 && dist[u] + w < dist[v]) {
            return true;
        }
    }

    return false;
}






// ============================================================
// 3. NEGATIVE CYCLE ANYWHERE IN GRAPH
//    No fixed source
// ============================================================

bool hasNegativeCycleAnywhere(int V, vector<vector<int>>& edges) {

    // Every vertex can act as a starting point
    vector<int> dist(V, 0);

    // Relax V-1 times
    for(int i = 0; i < V-1; i++) {

        for(auto edge : edges) {

            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            if(dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }

    // Vth relaxation
    for(auto edge : edges) {

        int u = edge[0];
        int v = edge[1];
        int w = edge[2];

        if(dist[u] + w < dist[v]) {
            return true;
        }
    }

    return false;
}






// ============================================================
// 4. NEGATIVE CYCLE ANYWHERE
//    Alternative approach: run Bellman-Ford from EVERY vertex
// ============================================================

bool hasNegativeCycleAnywhere(int V, vector<vector<int>>& edges) {

    for(int src = 0; src < V; src++) {

        vector<int> dist(V, 1e9);
        dist[src] = 0;

        // V-1 relaxations
        for(int i = 0; i < V-1; i++) {

            for(auto edge : edges) {

                int u = edge[0];
                int v = edge[1];
                int w = edge[2];

                if(dist[u] != 1e9 && dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                }
            }
        }

        // Check Vth relaxation
        for(auto edge : edges) {

            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            if(dist[u] != 1e9 && dist[u] + w < dist[v]) {
                return true;
            }
        }
    }

    return false;
}





// 1. Fixed source → shortest distances
//    INF everywhere
//    dist[src] = 0
//    return dist[]

// 2. Fixed source → negative cycle
//    INF everywhere
//    dist[src] = 0
//    Vth relaxation → cycle

// 3. Negative cycle anywhere
//    dist[] = 0 everywhere
//    Vth relaxation → cycle

// 4. Negative cycle anywhere (brute-force idea)
//    Run Bellman-Ford from every vertex