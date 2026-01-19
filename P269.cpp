/*
You are given a list of words sorted according to an unknown alien alphabet.
Your task is to deduce the order of characters in that alien language.
Example
words = ["wrt","wrf","er","ett","rftt"]
From the sorted list, we can infer:
w → e → r → t → f
Return any valid order:
"wertf"
*/

class Solution {
public:
    string alienOrder(vector<string>& words) {
        unordered_map<char, vector<char>> graph;
        unordered_map<char, int> indegree;

        // 1. Initialize all characters
        for (auto& w : words) {
            for (char c : w) {
                graph[c];
                indegree[c] = 0;
            }
        }

        // 2. Build graph from adjacent words
        for (int i = 0; i < words.size() - 1; i++) {
            string& w1 = words[i];
            string& w2 = words[i + 1];

            int len = min(w1.size(), w2.size());
            bool found = false;

            for (int j = 0; j < len; j++) {
                if (w1[j] != w2[j]) {
                    graph[w1[j]].push_back(w2[j]);
                    indegree[w2[j]]++;
                    found = true;
                    break;
                }
            }

            // prefix invalid case
            if (!found && w1.size() > w2.size())
                return "";
        }

        // 3. Topological sort
        queue<char> q;
        for (auto& [c, deg] : indegree) {
            if (deg == 0)
                q.push(c);
        }

        string res;
        while (!q.empty()) {
            char c = q.front(); q.pop();
            res.push_back(c);

            for (char nei : graph[c]) {
                if (--indegree[nei] == 0)
                    q.push(nei);
            }
        }

        // 4. Cycle check
        if (res.size() != indegree.size())
            return "";

        return res;
    }
};
