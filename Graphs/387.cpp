class Solution {
public:

    int findCheapestPrice(int n, vector<vector<int>>& flights,
                          int src, int dst, int k) {

        // Adjacency list
        unordered_map<int, list<pair<int, int>>> adj;

        for(auto flight : flights) {

            int u = flight[0];
            int v = flight[1];
            int price = flight[2];

            adj[u].push_back({v, price});
        }


        // dist[i] = cheapest cost to reach city i
        vector<int> dist(n, INT_MAX);

        dist[src] = 0;


        // {node, cost}
        queue<pair<int, int>> q;

        q.push({src, 0});


        // At most k stops = at most k + 1 flights
        int stops = 0;

        while(!q.empty() && stops <= k) {

            int size = q.size();

            // Important:
            // Use a copy so that updates made in this level
            // don't affect other nodes of the same level.
            vector<int> temp = dist;

            while(size--) {

                auto [node, cost] = q.front();
                q.pop();

                for(auto nbr : adj[node]) {

                    int nextNode = nbr.first;
                    int price = nbr.second;

                    int newCost = cost + price;

                    if(newCost < temp[nextNode]) {

                        temp[nextNode] = newCost;

                        q.push({nextNode, newCost});
                    }
                }
            }

            dist = temp;

            stops++;
        }


        if(dist[dst] == INT_MAX)
            return -1;

        return dist[dst];
    }
};