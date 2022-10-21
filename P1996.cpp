/*You are playing a game that contains multiple characters, and each of the characters has two main properties: attack and defense. You are given a 2D integer array properties where properties[i] = [attacki, defensei] represents the properties of the ith character in the game.

A character is said to be weak if any other character has both attack and defense levels strictly greater than this character's attack and defense levels. More formally, a character i is said to be weak if there exists another character j where attackj > attacki and defensej > defensei.

Return the number of weak characters.
Example 1:

Input: properties = [[5,5],[6,3],[3,6]]
Output: 0
Explanation: No character has strictly greater attack and defense than the other.
*/

class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        // sort first element small to large
        // if first elemenet is equivalent, sort second element from large to small
        auto comp = [](const vector<int>& a, const vector<int>& b){
            if (a[0] == b[0]){
                return a[1]>b[1];
            }
            return a[0]<b[0];
        };
        sort(properties.begin(), properties.end(), comp);
        int res(0);
        int tmp(INT_MIN); //  second element
        // check backward
        for (int i=properties.size()-1; i>=0; --i){
            // 0    4  res++
            // 1    5  tmp=5
            // 1    2  first res++
            // 2    4 
            // 2    1
            if (properties[i][1] < tmp){
                res++;
            }
            // keep track largest second element
            tmp = max(tmp, properties[i][1]); 
        }
        return res;
    }
};
