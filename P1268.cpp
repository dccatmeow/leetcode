/*
1268. Search Suggestions System
You are given an array of strings products and a string searchWord.

Design a system that suggests at most three product names from products after each character of searchWord is typed. Suggested products should have common prefix with searchWord. If there are more than three products with a common prefix return the three lexicographically minimums products.

Return a list of lists of the suggested products after each character of searchWord is typed.

 

Example 1:

Input: products = ["mobile","mouse","moneypot","monitor","mousepad"], searchWord = "mouse"
Output: [["mobile","moneypot","monitor"],["mobile","moneypot","monitor"],["mouse","mousepad"],["mouse","mousepad"],["mouse","mousepad"]]
Explanation: products sorted lexicographically = ["mobile","moneypot","monitor","mouse","mousepad"].
After typing m and mo all products match and we show user ["mobile","moneypot","monitor"].
After typing mou, mous and mouse the system suggests ["mouse","mousepad"].

*/

struct Trie{
    Trie(char c){
        value = c;
    }
    char value;
    map<char, Trie*> children;
    vector<string> suggestions;
};

class Solution {
public:
    void insertTrie(Trie* node, string w){
        for(int i=0; i<w.size();++i){
            char c = w[i];
            if (node->children.find(c)==node->children.end()){
                node->children[c]=new Trie(c);
            }
            node = node->children[c];
            if (node->suggestions.size()<3){
                node->suggestions.push_back(w);
            }
        }
    }
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        if(searchWord.empty()){
            return {products};
        }
        vector<vector<string>> res(searchWord.size());
        // sort
        sort(products.begin(), products.end());
        // create trie
        Trie* root = new Trie('0');
        for (auto& str:products){
            insertTrie(root, str);
        }
        // collect result
        for (int i=0; i<searchWord.size();++i){
            if (root->children.find(searchWord[i])!=root->children.end()){
                root = root->children[searchWord[i]];
            }else{
                break;
            }
            res[i] = root->suggestions;
        }
        return res;
    }
};
