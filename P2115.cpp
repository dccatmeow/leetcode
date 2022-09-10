/*
DFS with loop detection.

You have information about n different recipes. You are given a string array recipes and a 2D string array ingredients. 
The ith recipe has the name recipes[i], and you can create it if you have all the needed ingredients from ingredients[i]. 
Ingredients to a recipe may need to be created from other recipes, i.e., ingredients[i] may contain a string that is in recipes.

You are also given a string array supplies containing all the ingredients that you initially have, and you have an infinite supply of all of them.

Return a list of all the recipes that you can create. You may return the answer in any order.

Note that two recipes may contain each other in their ingredients.

Example 1:

Input: recipes = ["bread"], ingredients = [["yeast","flour"]], supplies = ["yeast","flour","corn"]
Output: ["bread"]
*/
class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        for(auto s:supplies){
            su.insert(s);
        }
        int n=recipes.size();
        for (int i=0; i<n; ++i){
            re[recipes[i]] = i;
        }
        
        for (int i=0; i< n; ++i){
            // check all the recipes
            unordered_set<int> path;
            canCreate(i, recipes, ingredients, path);
        }
        return res;
    }
    
    bool canCreate(int i, vector<string>& recipes, vector<vector<string>>& ingredients, unordered_set<int>& path){
        // check if recipes has been visited
        if (su.count(recipes[i])){
            return true;
        }
        // check if it already on path
        if (path.count(i)){
            return false;
        }else{
            path.insert(i);
        }
        // check if recipes[i] can be created
        for (auto c: ingredients[i]){
            if (!su.count(c)){
                if (re.count(c)){
                    // ingredient is another recipe
                    if (!canCreate(re[c],recipes, ingredients, path)){
                        return false;
                    }
                }else{
                    // not in supplier or recipe
                    return false;
                }
            }
        }
        // add this recipes in res and supplier names
        res.push_back(recipes[i]);
        su.insert(recipes[i]);
        // remove recipe i from path
        path.erase(i);
        return true;
    }
private: 
    // supplier names
    unordered_set<string> su;
    // recipes name and position
    unordered_map<string, int> re;
    vector<string> res;
};
