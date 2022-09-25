/*
There are n people in a social group labeled from 0 to n - 1. You are given an array logs where logs[i] = [timestampi, xi, yi] 
indicates that xi and yi will be friends at the time timestampi.

Friendship is symmetric. That means if a is friends with b, then b is friends with a. Also, person a is acquainted with a person b 
if a is friends with b, or a is a friend of someone acquainted with b.

Return the earliest time for which every person became acquainted with every other person. If there is no such earliest time, return -1.
Example 1:

Input: logs = [[20190101,0,1],[20190104,3,4],[20190107,2,3],[20190211,1,5],[20190224,2,4],[20190301,0,3],[20190312,1,2],[20190322,4,5]], n = 6
Output: 20190301
*/
class Solution {
public:
    int earliestAcq(vector<vector<int>>& logs, int n) {
        // sort logs by timestamp
        auto comp=[](const vector<int>& v1, const vector<int>& v2){
            return v1[0]<v2[0];
        };
        sort(logs.begin(), logs.end(), comp);
        // initialize parent
        p.resize(n);
        for (int i=0; i<n; ++i){
            p[i]=i;
        }
        unionCnt=n;
        for (auto v:logs){
            unionP(v[1], v[2]);
            if (unionCnt == 1){
                return v[0];
            }
        }
        return -1;
    }
    void unionP(int a, int b){
        int ap = findP(a);
        int bp = findP(b);
        if (ap==bp){
            return;
        }else{
            if (ap<bp){
                p[bp] = ap;
            }else{
                p[ap] = bp;
            }
            unionCnt--;
        }
    }
    
    int findP(int a){
        if (p[a] != a){
            return findP(p[a]);
        }else{
            return p[a];
        }
    }
private:
    vector<int> p;
    int unionCnt;
};
