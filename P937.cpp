/*
    You are given an array of logs. Each log is a space-delimited string of words, where the first word is the identifier.

There are two types of logs:

Letter-logs: All words (except the identifier) consist of lowercase English letters.
Digit-logs: All words (except the identifier) consist of digits.
Reorder these logs so that:

The letter-logs come before all digit-logs.
The letter-logs are sorted lexicographically by their contents. If their contents are the same, then sort them lexicographically by their identifiers.
The digit-logs maintain their relative ordering.
Return the final order of the logs.

*/

class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        // We can break this problem into two tasks: 1) Parition 2) Sort letter-logs
        // Partition: letter-logs at the front, digit-logs at the back.
        // We're using stable_partition instead of partition to retain the original order.
        // stable_partition returns an iterator to the first element of the second group.
        // first separate alphabet and number content
        auto comp = [](const string& str){
            // first content after identifier
            auto idx = str.find(' ')+1; 
            return isalpha(str[idx]);
        };
        auto iter = stable_partition(logs.begin(), logs.end(), comp);
        // sort
        auto comp2 = [](const string& str1, const string& str2){
            // content
            auto substr1 = string(str1.begin()+str1.find(' '), str1.end());
            auto substr2 = string(str2.begin()+str2.find(' '), str2.end());
            if (substr1 == substr2){
                // compare identifier
                return str1<str2;
            }
            return substr1<substr2;
        };
        sort(logs.begin(), iter, comp2);
        return logs;

    }
};
