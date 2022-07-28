/*
A website domain "discuss.leetcode.com" consists of various subdomains. At the top level, we have "com", 
at the next level, we have "leetcode.com" and at the lowest level, "discuss.leetcode.com". 
When we visit a domain like "discuss.leetcode.com", we will also visit the parent domains "leetcode.com" and "com" implicitly.

A count-paired domain is a domain that has one of the two formats "rep d1.d2.d3" or "rep d1.d2" 
where rep is the number of visits to the domain and d1.d2.d3 is the domain itself.

For example, "9001 discuss.leetcode.com" is a count-paired domain that indicates that discuss.leetcode.com was visited 9001 times.
Given an array of count-paired domains cpdomains, return an array of the count-paired domains of each subdomain in the input. 
You may return the answer in any order.

Example 1:

Input: cpdomains = ["9001 discuss.leetcode.com"]
Output: ["9001 leetcode.com","9001 discuss.leetcode.com","9001 com"]
*/

class Solution {
public:
    void getStrCount(string str, unordered_map<string, int>& myMap, int count){
            int idx = str.find(".");
            if (idx!=string::npos){
                // if there is substring after . add to the map
                string str_part = str.substr(idx+1);
                myMap[str_part] += count;
                getStrCount(str_part, myMap, count);
            }
    }
    
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        unordered_map<string, int> myMap;         
        for (auto str:cpdomains){          
            // seperate count and string
            int idx = str.find(" ");
            int count = stoi(str.substr(0, idx));
            string str_part = str.substr(idx+1);
            // add string and count to map
            myMap[str_part] += count;
            // get string and count for substring
            getStrCount(str_part, myMap, count);
        }
            
        vector<string> res;
        for (auto elem:myMap){
            // format result
            res.push_back(to_string(elem.second)+" "+elem.first);
        }
        return res;   
    }
};
