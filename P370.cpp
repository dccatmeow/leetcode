/*
You are given an integer length and an array updates where updates[i] = [startIdxi, endIdxi, inci].

You have an array arr of length length with all zeros, and you have some operation to apply on arr. In the ith operation, you should increment all the elements arr[startIdxi], arr[startIdxi + 1], ..., arr[endIdxi] by inci.

Return arr after applying all the updates.
*/
class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        vector<int> event(length, 0);
        vector<int> res(length);
        int val(0);
        for (auto elem:updates){
            event[elem[0]] += elem[2];
            // if second element in elem is last one ini the array, then no event needed
            if (elem[1]+1<length){
                event[elem[1]+1] -=elem[2];
            }
        }
        for (int i=0;i<length;++i){
            val +=event[i];
            res[i] = val;
        }
        return res;
    }
};
