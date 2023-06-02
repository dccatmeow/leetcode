/*
721. Accounts Merge
Given a list of accounts where each element accounts[i] is a list of strings, where the first element accounts[i][0] is a name, and the rest of the elements are emails representing emails of the account.

Now, we would like to merge these accounts. Two accounts definitely belong to the same person if there is some common email to both accounts. Note that even if two accounts have the same name, they may belong to different people as people could have the same name. A person can have any number of accounts initially, but all of their accounts definitely have the same name.

After merging the accounts, return the accounts in the following format: the first element of each account is the name, and the rest of the elements are emails in sorted order. The accounts themselves can be returned in any order.

*/

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        for(int i=0;i<accounts.size();++i){
            // ID is i
            for (int j=1; j<accounts[i].size();++j){
                emailToID[accounts[i][j]].push_back(i);
            }
        }
        // reset parent to its own
        parent.resize(accounts.size());
        for (int i=0; i<accounts.size();++i){
            parent[i] = i;
        }
        // edge is stored in emailToID
        for (auto& elem:emailToID){
            if (elem.second.size()>1){
                for (int i=1; i<elem.second.size();++i){
                    Union(elem.second[i-1], elem.second[i]);
                }
            }
        }
        unordered_map<int, set<string>> m;
        // get all the union
        for (int i=0; i<accounts.size();++i){
            int id = findP(i);
            for (int j=1; j<accounts[i].size();++j){
                m[id].insert(accounts[i][j]);
            }
        }
        vector<vector<string>> res;
        for (auto& elem:m){
            vector<string> tmp;
            tmp.push_back(accounts[elem.first][0]);
            for (auto& e:elem.second){
                tmp.push_back(e);
            }
            res.push_back(tmp);
        }
        return res;
        
    }
    
    void Union(int i, int j){
        int i_p = findP(i);
        int j_p = findP(j);
        if (i_p == j_p){
            return;
        }else if (i_p<j_p){
            parent[j_p] = i_p;
        }else{
            parent[i_p] = j_p;
        }
    }
    
    int findP(int i){
        if (i == parent[i]){
            return i;
        }
        return findP(parent[i]);
    }
private:
    unordered_map<string, vector<int>> emailToID;
    vector<int> parent;
};
