/*
139. Word Break

Given a string s and a dictionary of strings wordDict, return true if s can be segmented into a space-separated sequence of one or more dictionary words.

Note that the same word in the dictionary may be reused multiple times in the segmentation.

Example 1:

Input: s = "leetcode", wordDict = ["leet","code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".
*/

struct TrieNode{
    unordered_map<char, TrieNode*> children;
    bool isWord; // label end of word
    TrieNode(){
        isWord = false;
        children = unordered_map<char, TrieNode*>();
    }
};

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        // construct trie
        auto root = new TrieNode();
        for (auto& w:wordDict){
            auto node = root;
            for (auto c:w){
                if (node->children.find(c)==node->children.end()){
                    node->children[c] = new TrieNode();
                }
                node = node->children[c];
            }
            node->isWord = true;// label end of word
        }
        int n=s.size();
        vector<bool> dp(n,false);
        for (int i=0; i<n; ++i){
            // starting from i to find the word
            if (i==0 || dp[i-1]){
                // update dp for found word
                auto node = root;
                int j=i;
                while(j<n && node->children.find(s[j]) != node->children.end()){
                    node = node->children[s[j]]; 
                    if (node->isWord){
                        dp[j] = true;
                    }
                    j++;
                }
            }
        }
        return dp[n-1];
    }
};
