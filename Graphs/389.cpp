class Solution {
public:

    int bfs(int m, int n,
            vector<vector<bool>>& visited,
            queue<tuple<int,int,int>>& q,
            int d) {

        while (!q.empty()) {

            auto [j1, j2, steps] = q.front();
            q.pop();

            if (j1 == d || j2 == d)
                return steps;


            // 1. Fill A
            if (j1 != m && !visited[m][j2]) {
                visited[m][j2] = true;
                q.push({m, j2, steps + 1});
            }


            // 2. Fill B
            if (j2 != n && !visited[j1][n]) {
                visited[j1][n] = true;
                q.push({j1, n, steps + 1});
            }


            // 3. Empty A
            if (j1 != 0 && !visited[0][j2]) {
                visited[0][j2] = true;
                q.push({0, j2, steps + 1});
            }


            // 4. Empty B
            if (j2 != 0 && !visited[j1][0]) {
                visited[j1][0] = true;
                q.push({j1, 0, steps + 1});
            }


            // 5. Pour A -> B
            if (j1 != 0 && j2 != n) {

                int transfer = min(j1, n - j2);

                int newJ1 = j1 - transfer;
                int newJ2 = j2 + transfer;

                if (!visited[newJ1][newJ2]) {
                    visited[newJ1][newJ2] = true;
                    q.push({newJ1, newJ2, steps + 1});
                }
            }


            // 6. Pour B -> A
            if (j2 != 0 && j1 != m) {

                int transfer = min(j2, m - j1);

                int newJ1 = j1 + transfer;
                int newJ2 = j2 - transfer;

                if (!visited[newJ1][newJ2]) {
                    visited[newJ1][newJ2] = true;
                    q.push({newJ1, newJ2, steps + 1});
                }
            }
        }

        return -1;
    }


    int minSteps(int m, int n, int d) {

        if (d > max(m, n))
            return -1;

        vector<vector<bool>> visited(
            m + 1,
            vector<bool>(n + 1, false)
        );

        queue<tuple<int,int,int>> q;

        q.push({0, 0, 0});
        visited[0][0] = true;

        return bfs(m, n, visited, q, d);
    }
};