/*

*/

class Solution {
public:
    vector<int> res;
    vector<int> arra;
    vector<int> pancakeSort(vector<int>& arr) {
        arra = arr; 
        bt(arra.size());
        return res;
    }
    
    void bt(int k){
        // only first k element needs flip, 
        // the rest of element in arr is already sorted
        for(int i=0; i<k; ++i){
            if (arra[i]==k){
                // flip i to the 0 position
                res.push_back(i+1);
                flip(i+1);
                // flip i to k position
                res.push_back(k);
                flip(k);
                bt(k-1);
                break;
            }
        }
    }
    
    void flip(int k){
        int tmp;
        int i=0;
        int j=k-1;
        while (i<j){
            tmp = arra[i];
            arra[i] = arra[j];
            arra[j] = tmp;
            i++;
            j--;
        }
    }
};
