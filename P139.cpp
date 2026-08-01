/*
139. Word Break

Given a string s and a dictionary of strings wordDict, return true if s can be segmented into a space-separated sequence of one or more dictionary words.

Note that the same word in the dictionary may be reused multiple times in the segmentation.

Example 1:

Input: s = "leetcode", wordDict = ["leet","code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".
*/
class Solution {
public:
    struct TrieNode {
        unordered_map<char, TrieNode*> children;
        bool isWord = false;
    };

    bool wordBreak(string s, vector<string>& wordDict) {
        str = s;
        root = new TrieNode();

        // dp[start] represents whether the substring str[start ... end] can be completely segmented into words from wordDict
        // -1 = unknown, 0 = false, 1 = true
        dp.assign(s.size(), -1);

        for (auto &elem : wordDict) {
            auto node = root;
            for (char c : elem) {
                if (node->children.find(c)==node->children.end())
                    node->children[c] = new TrieNode();
                node = node->children[c];
            }
            node->isWord = true;
        }
        return findInWordDict(0);
    }

    bool findInWordDict(int start) {
        // last element passed
        if (start == str.size())
            return true;
        // visited
        if (dp[start] != -1) {
            if (dp[start] == 1)
                return true;
            else
                return false;
        }
        auto node = root;
        for (int i = start; i < str.size(); i++) {
            if (node->children.find(str[i]) == node->children.end()) {
                break;
            }
            node = node->children[str[i]];
            if (node->isWord) {
                // from root search s[i+1]
                if (findInWordDict(i + 1)) {
                    // all words i+1 to end is found in dictionary
                    // [start,i] is already a word
                    dp[start] = 1;
                    return true;
                }
            }
        }
        dp[start] = 0; // cannot find all words in dictionary in [start, s_end]
        return false;
    }

private:
    TrieNode *root;
    string str;
    vector<int> dp;
};
