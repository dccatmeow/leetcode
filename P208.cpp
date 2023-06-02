/*
208. Implement Trie (Prefix Tree)
A trie (pronounced as "try") or prefix tree is a tree data structure used to efficiently store and retrieve keys in a dataset of strings. There are various applications of this data structure, such as autocomplete and spellchecker.

Implement the Trie class:

Trie() Initializes the trie object.
void insert(String word) Inserts the string word into the trie.
boolean search(String word) Returns true if the string word is in the trie (i.e., was inserted before), and false otherwise.
boolean startsWith(String prefix) Returns true if there is a previously inserted string word that has the prefix prefix, and false otherwise.
 

Example 1:

Input
["Trie", "insert", "search", "search", "startsWith", "insert", "search"]
[[], ["apple"], ["apple"], ["app"], ["app"], ["app"], ["app"]]
Output
[null, null, true, false, true, null, true]
*/

class TrieNode{
public:
    TrieNode* child[26]; // child can be any of 26 letters, use array to trace
    TrieNode(){
        // initialize
        isWord = false;
        for (auto &a:child){
            a = nullptr;
        }
    }
    bool isWord; // label the end of word
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* p = root;
        for (auto& e:word){
            int i=e-'a';
            if (!p->child[i]){
                p->child[i] = new TrieNode();
            }
            p = p->child[i];
        }
        p->isWord = true; // set word at last letter
    }
    
    bool search(string word, bool prefix=false) {
        TrieNode* p = root;
        for (auto& e:word){
            int i=e-'a';
            if (!p->child[i]){
                return false;
            }else{
                p = p->child[i];
            }
        }
        if (!prefix){
            // check word
            return p->isWord;
        }
        return true;
    }
    
    bool startsWith(string prefix) {
        return search(prefix, true);
    }
private:
    TrieNode* root;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
