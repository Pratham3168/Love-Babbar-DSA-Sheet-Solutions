// ============= NORMAL DFS=======================

// class Solution {
// public:

//     void dfs(vector<vector<int>>& image, int i, int j,
//              int originalColor, int newColor)
//     {
//         int m = image.size();
//         int n = image[0].size();

//         // Out of bounds
//         if(i < 0 || i >= m || j < 0 || j >= n)
//             return;

//         // Different color
//         if(image[i][j] != originalColor)
//             return;

//         // Color the current cell
//         image[i][j] = newColor;

//         // Visit all 4 neighbours
//         dfs(image, i - 1, j, originalColor, newColor); // Up
//         dfs(image, i + 1, j, originalColor, newColor); // Down
//         dfs(image, i, j - 1, originalColor, newColor); // Left
//         dfs(image, i, j + 1, originalColor, newColor); // Right
//     }

//     vector<vector<int>> floodFill(vector<vector<int>>& image,
//                                   int sr, int sc, int color) {

//         int originalColor = image[sr][sc];

//         // Already the desired color
//         if(originalColor == color)
//             return image;

//         dfs(image, sr, sc, originalColor, color);

//         return image;
//     }
// };




// =========== USING GRAPH AND DFS=====================
// class Solution {
// public:

//     void prepareAdjList(vector<vector<int>>& image,
//                         vector<vector<int>>& adjList,
//                         int originalColor) {

//         int m = image.size();
//         int n = image[0].size();

//         int dx[] = {-1, 1, 0, 0};
//         int dy[] = {0, 0, -1, 1};

//         for (int i = 0; i < m; i++) {
//             for (int j = 0; j < n; j++) {

//                 if (image[i][j] != originalColor)
//                     continue;

//                 int u = i * n + j;

//                 for (int k = 0; k < 4; k++) {

//                     int newX = i + dx[k];
//                     int newY = j + dy[k];

//                     if (newX >= 0 && newX < m &&
//                         newY >= 0 && newY < n &&
//                         image[newX][newY] == originalColor) {

//                         int v = newX * n + newY;
//                         adjList[u].push_back(v);
//                     }
//                 }
//             }
//         }
//     }

//     vector<vector<int>> floodFill(vector<vector<int>>& image,
//                                   int sr, int sc, int color) {

//         int m = image.size();
//         int n = image[0].size();

//         int originalColor = image[sr][sc];

//         if (originalColor == color)
//             return image;

//         vector<vector<int>> adjList(m * n);

//         prepareAdjList(image, adjList, originalColor);

//         int src = sr * n + sc;

//         queue<int> q;
//         vector<bool> visited(m * n, false);

//         q.push(src);
//         visited[src] = true;

//         while (!q.empty()) {

//             int node = q.front();
//             q.pop();

//             int row = node / n;
//             int col = node % n;

//             image[row][col] = color;

//             for (int neighbour : adjList[node]) {

//                 if (!visited[neighbour]) {

//                     visited[neighbour] = true;
//                     q.push(neighbour);
//                 }
//             }
//         }

//         return image;
//     }
// };