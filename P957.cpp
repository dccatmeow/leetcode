// 957. Prison Cells After N Days
/*
  There are 8 prison cells in a row and each cell is either occupied or vacant.

Each day, whether the cell is occupied or vacant changes according to the following rules:

If a cell has two adjacent neighbors that are both occupied or both vacant, then the cell becomes occupied.
Otherwise, it becomes vacant.
Note that because the prison is a row, the first and the last cells in the row can't have two adjacent neighbors.

You are given an integer array cells where cells[i] == 1 if the ith cell is occupied and cells[i] == 0 if the ith cell is vacant, and you are given an integer n.

Return the state of the prison after n days (i.e., n such changes described above).


*/

class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int n) {
        // use string as key
        unordered_map<string, int> m;
        // step 0
        string tmp;
        for (auto e:cells){
            tmp += to_string(e);
        }
        m[tmp]=0;
        for (int i=0; i<n;++i){
            // get tmp, boundary char always 0
            string new_tmp = "0";
            for (int j=1;j<tmp.size()-1;++j){
                if (tmp[j-1]==tmp[j+1]){
                    new_tmp+='1';
                }else{
                    new_tmp+='0';
                }
            }
            // last char
            new_tmp = new_tmp+'0';
            tmp = new_tmp;
            if (m.find(tmp)==m.end()){
                m[tmp]=i;
            }else{
                // find a circle
                // rest n-i
                // circle length i-m[tmp]
                n = i+(n-i)%(i-m[tmp]);
            }
            
        }
        for (int i=0;i<tmp.size();++i){
            cells[i]=tmp[i]-'0';
        }
        return cells;
    }
};
