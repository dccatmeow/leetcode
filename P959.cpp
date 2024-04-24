959. Regions Cut By Slashes

An n x n grid is composed of 1 x 1 squares where each 1 x 1 square consists of a '/', '\', or blank space ' '. These characters divide the square into contiguous regions.

Given the grid grid represented as a string array, return the number of regions.

Note that backslash characters are escaped, so a '\' is represented as '\\'.

class Solution {
public:
    vector<int> p;
    int res = 1;
    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        // '\', n=1, 2 node per row
        int N = n+1; // need extra node to represent outline
        p = vector<int>(N*N,0);
        // all boundary has same parent 0
        // set inner node parent
        for (int i=1; i<N-1; i++){
            for (int j=1; j<N-1;j++){
                p[i*N+j] = i*N+j;
            }
        }
        for (int i=0; i<n;++i){
            for (int j=0; j<n; ++j){
                if (grid[i][j] == '/'){
                    // i,j     i, j+1
                    // i+1,j   i+1,j+1
                    int p1 = findP(i*N+j+1);
                    int p2 = findP((i+1)*N+j);
                    unionP(p1,p2);
                }else if (grid[i][j] == '\\'){
                    int p1 = findP(i*N+j);
                    int p2 = findP((i+1)*N+j+1);
                    unionP(p1,p2);
                }
            }
        }
        return res;
    }
    int findP(int node){
        if (node == p[node]){
            return node;
        }
        return findP(p[node]);
    }
    void unionP(int p1, int p2){
        if (p1==p2){
            res++;
        }else{
            p[p1] = p2;
        }
    }

};
