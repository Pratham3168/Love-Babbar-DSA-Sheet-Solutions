/*
============================================================
                FLOYD-WARSHALL ALGORITHM
============================================================

Purpose:
    Find the shortest distance between EVERY pair of nodes.

Idea:
    For every pair (i, j), try every node k as an
    intermediate node.

        i → j

    OR

        i → k → j

    Take the minimum of both.

Core Formula:
    matrix[i][j] = min(matrix[i][j],
                       matrix[i][k] + matrix[k][j]);

Steps:
    1. Convert -1 (no path) to INF.
    2. Set matrix[i][i] = 0.
    3. Try every node k as an intermediate node.
    4. Convert INF back to -1.

Loop Order:
    k → i → j

Complexity:
    Time  : O(V^3)
    Space : O(1) extra

Important:
    Floyd-Warshall can handle negative edge weights,
    but a negative weight cycle should not be present
    when finding shortest distances.
============================================================
*/

class Solution {
public:
    void shortest_distance(vector<vector<int>>& matrix) {

        int n = matrix.size();

        // Step 1: Convert -1 to INF
        //         Set distance from node to itself = 0
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {

                if(matrix[i][j] == -1) {
                    matrix[i][j] = 1e9;
                }

                if(i == j) {
                    matrix[i][j] = 0;
                }
            }
        }

        // Step 2: Floyd-Warshall
        for(int k = 0; k < n; k++) {

            for(int i = 0; i < n; i++) {

                for(int j = 0; j < n; j++) {

                    matrix[i][j] = min(
                        matrix[i][j],
                        matrix[i][k] + matrix[k][j]
                    );
                }
            }
        }

        // Step 3: Convert INF back to -1
        for(int i = 0; i < n; i++) {

            for(int j = 0; j < n; j++) {

                if(matrix[i][j] == 1e9) {
                    matrix[i][j] = -1;
                }
            }
        }
    }
};