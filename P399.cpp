/*
You are given an array of variable pairs equations and an array of real numbers values, where equations[i] = [Ai, Bi] and values[i] 
represent the equation Ai / Bi = values[i]. Each Ai or Bi is a string that represents a single variable.

You are also given some queries, where queries[j] = [Cj, Dj] represents the jth query where you must find the answer for Cj / Dj = ?.

Return the answers to all queries. If a single answer cannot be determined, return -1.0.

Note: The input is always valid. You may assume that evaluating the queries will not result in division by zero and that there is no contradiction.

Example 1:

Input: equations = [["a","b"],["b","c"]], values = [2.0,3.0], queries = [["a","c"],["b","a"],["a","e"],["a","a"],["x","x"]]
Output: [6.00000,0.50000,-1.00000,1.00000,-1.00000]
Explanation: 
Given: a / b = 2.0, b / c = 3.0
queries are: a / c = ?, b / a = ?, a / e = ?, a / a = ?, x / x = ?
return: [6.0, 0.5, -1.0, 1.0, -1.0 ]
*/

class Solution {
public:
    using pdi = std::pair<double, int>;
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        // simplify the problem by hashing string to int
        int c=0;
        for (auto v:equations){
            if(!m.count(v[0])){
                // v[0] not exist in the map
                // add new element in m
                // add element point to itself in data
                m[v[0]] = c;
                data.push_back({1,c});
                c++;
            }
            if(!m.count(v[1])){
                // v[1] not exist in the map
                m[v[1]] = c;
                data.push_back({1,c});
                c++;
            }
        }
        
        // loop through equations again to find the union
        for (int i=0; i<equations.size(); ++i){
            int n1 = m[equations[i][0]];
            int n2 = m[equations[i][1]];
            myUnion(n1, n2, values[i]);
        }
               
        // calculate queries
        vector<double> res;
        for (auto e:queries){
            if ( !m.count(e[0]) || !m.count(e[1])){
                // element not exist
                res.push_back(-1);
                continue;
            }
            pdi n1 = findP(m[e[0]]);
            pdi n2 = findP(m[e[1]]);
            if (n1.second == n2.second){
                res.push_back(n1.first/n2.first);
            }else{
                res.push_back(-1);
            }
        }
        return res;
    }
    
    pdi findP (int i){
        pdi tmp = data[i];
        if (tmp.second == i){
            // point to itself
            return tmp;
        }else{
            // continue loop through until met with the tip
            pdi tmp1 = findP(tmp.second);
            return {tmp1.first*tmp.first, tmp1.second};
        }
    }
    
    void myUnion(int e1, int e2, double v){
        // union e1 and e2
        // find the most tip of each element then connect them
        pdi tmp1 = findP(e1);
        pdi tmp2 = findP(e2);
        if (tmp1.second != tmp2.second){
            // connect tmp1 with tmp2
            data[tmp1.second] = pdi(tmp2.first*v/tmp1.first ,tmp2.second);
        }
    }
private:
    // hashing string to int for all the string in equations
    unordered_map<string, int> m;
    // data[0] means string 0 is connect with a pdi
    vector<pdi> data;
               
};
