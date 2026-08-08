

class Solution {
public:

    bool topoSort(char node,
                  unordered_map<char, list<char>> &adjList,
                  stack<char> &st,
                  unordered_map<char, bool> &visited,
                  unordered_map<char, bool> &dfsVisited)
    {
        visited[node] = true;
        dfsVisited[node] = true;

        for(char neighbor : adjList[node]) {

            // Cycle detected
            if(dfsVisited[neighbor]) {
                return false;
            }

            if(!visited[neighbor]) {
                bool check = topoSort(neighbor, adjList, st,
                                       visited, dfsVisited);

                if(!check) {
                    return false;
                }
            }
        }

        dfsVisited[node] = false;
        st.push(node);

        return true;
    }


    string findOrder(vector<string> &words) {

        unordered_map<char, list<char>> adjList;

        // 1. Add every unique character to the graph
        for(string word : words) {
            for(char ch : word) {
                adjList[ch];
            }
        }


        // 2. Create edges using first different character
        for(int i = 0; i < words.size() - 1; i++) {

            string word1 = words[i];
            string word2 = words[i + 1];

            int len = min(word1.size(), word2.size());

            bool foundDifference = false;

            for(int j = 0; j < len; j++) {

                if(word1[j] != word2[j]) {

                    adjList[word1[j]].push_back(word2[j]);

                    foundDifference = true;
                    break;
                }
            }

            // Invalid prefix case
            if(!foundDifference && word1.size() > word2.size()) {
                return "";
            }
        }


        // 3. Topological sort
        stack<char> st;

        unordered_map<char, bool> visited;
        unordered_map<char, bool> dfsVisited;

        for(auto &node : adjList) {

            if(!visited[node.first]) {

                bool check = topoSort(node.first, adjList,
                                      st, visited, dfsVisited);

                // Cycle exists
                if(!check) {
                    return "";
                }
            }
        }


        // 4. Construct answer
        string ans = "";

        while(!st.empty()) {

            ans += st.top();
            st.pop();
        }

        return ans;
    }
};

