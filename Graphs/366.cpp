/*
APPROACH:
- Do not explicitly build the graph.
- Store all words in an unordered_set for fast lookup.
- During BFS, generate neighbors by changing one character at a time.
- For every position, try characters from 'a' to 'z'.
- If the generated word exists in the dictionary, it is a valid neighbor.
- Use BFS because we need the shortest transformation sequence.
- Use visited to avoid processing the same word again.

TIME: O(N * L * 26) ≈ O(N * L)
SPACE: O(N)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

        unordered_set<string> dictionary(wordList.begin(), wordList.end());

        if(dictionary.find(endWord) == dictionary.end()) {
            return 0;
        }

        queue<string> q;
        unordered_set<string> visited;

        q.push(beginWord);
        visited.insert(beginWord);

        int count = 1;

        while(!q.empty()) {

            int size = q.size();

            while(size--) {

                string word = q.front();
                q.pop();

                if(word == endWord) {
                    return count;
                }

                for(int i = 0; i < word.length(); i++) {

                    char original = word[i];

                    for(char ch = 'a'; ch <= 'z'; ch++) {

                        if(ch == original) {
                            continue;
                        }

                        word[i] = ch;

                        if(dictionary.find(word) != dictionary.end() &&
                           visited.find(word) == visited.end()) {

                            visited.insert(word);
                            q.push(word);
                        }
                    }

                    word[i] = original;
                }
            }

            count++;
        }

        return 0;
    }
};












/*
APPROACH:
- Treat every word as a node of an undirected graph.
- Compare every pair of words.
- If two words differ by exactly one character, add an edge between them.
- Run BFS from beginWord to endWord.
- Use visited to avoid cycles.
- count represents the number of words in the current BFS level.

TIME: O(N^2 * L)
SPACE: O(N^2 * L)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool isOneLetterDifferent(string a, string b) {

        int diff = 0;

        for(int i = 0; i < a.length(); i++) {
            if(a[i] != b[i]) {
                diff++;
            }
        }

        return diff == 1;
    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

        vector<string> words = wordList;
        words.push_back(beginWord);

        unordered_map<string, vector<string>> adj;

        for(int i = 0; i < words.size(); i++) {

            for(int j = i + 1; j < words.size(); j++) {

                if(isOneLetterDifferent(words[i], words[j])) {

                    adj[words[i]].push_back(words[j]);
                    adj[words[j]].push_back(words[i]);
                }
            }
        }

        queue<string> q;
        unordered_set<string> visited;

        q.push(beginWord);
        visited.insert(beginWord);

        int count = 1;

        while(!q.empty()) {

            int size = q.size();

            while(size--) {

                string word = q.front();
                q.pop();

                if(word == endWord) {
                    return count;
                }

                for(string nbr : adj[word]) {

                    if(visited.find(nbr) == visited.end()) {

                        visited.insert(nbr);
                        q.push(nbr);
                    }
                }
            }

            count++;
        }

        return 0;
    }
};