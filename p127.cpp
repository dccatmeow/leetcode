/*
127. Word Ladder
A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:

Every adjacent pair of words differs by a single letter.
Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
sk == endWord
Given two words, beginWord and endWord, and a dictionary wordList, return the number of words in the shortest transformation sequence from beginWord to endWord, or 0 if no such sequence exists.

 

Example 1:

Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
Output: 5
Explanation: One shortest transformation sequence is "hit" -> "hot" -> "dot" -> "dog" -> cog", which is 5 words long.
*/

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if (dict.find(endWord)==dict.end()){
            return 0;
        }
        queue<string> q;
        q.push(beginWord);
        int cnt=0;
        while(!q.empty()){
            cnt++;
            int n=q.size();
            for (int i=0;i<n;++i){
                string tmp = q.front();
                if (tmp==endWord){
                    return cnt;
                }
                q.pop();
                for (int j=0; j<tmp.size();++j){
                    for (char k='a';k<='z';++k){
                        char c = tmp[j];
                        tmp[j] = k;
                        if (dict.find(tmp)!=dict.end()){
                            dict.erase(tmp);
                            q.push(tmp);
                        }
                        tmp[j] = c;
                    }
                }
            }
        }
        return 0;
    }
};
// Time Complexity O(size of wordlist * size of beginWord*26)
// space complexity is O(n)
