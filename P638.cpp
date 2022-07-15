
/*
In LeetCode Store, there are n items to sell. Each item has a price. However, there are some special offers, 
and a special offer consists of one or more different kinds of items with a sale price.

You are given an integer array price where price[i] is the price of the ith item, and an integer array needs where needs[i] 
is the number of pieces of the ith item you want to buy.

You are also given an array special where special[i] is of size n + 1 where special[i][j] is the number of pieces of the jth 
item in the ith offer and special[i][n] (i.e., the last integer in the array) is the price of the ith offer.

Return the lowest price you have to pay for exactly certain items as given, where you could make optimal use of the special offers. 
You are not allowed to buy more items than you want, even if that would lower the overall price. 
You could use any of the special offers as many times as you want.

Example 1:

Input: price = [2,5], special = [[3,0,5],[1,2,10]], needs = [3,2]
Output: 14
*/
// Recursive with cache


class Solution {
public:
    int getKey(const vector<int>& needs){
        // when needs = [1, 2, 3, 4, 5, 6]
        // key = 123456
        int key = 0;
        for(auto n:needs) {
            key = (key*11+n);
        }
        return key;
    }
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        // Memorize price for each intermediate needs
            // check if the key exist in cache
        int key = getKey(needs);
        if (cache.count(key)){
            return cache[key];
        }
        
        // Find the worst price where no special offer is taken
        int res = std::inner_product(price.begin(), price.end(), needs.begin(), 0);
        if (res == 0){
            return res;
        }
        int n = needs.size();
        
        // loop through each special promotion
        for (auto& s:special){
            // for each need deduct the promotion
            // e.g. needs [3,2] needs.size() == n
            // promotion [1,1,3] s.size()==n+1
            // newNeeds [2,1]
            auto newNeeds = needs;
            bool flag = true;
            for (int i = 0; i<n;++i){
                if (s[i]>newNeeds[i]){
                    // promotion is more than needs, cannot use promotion
                    flag = false;
                    break;
                }else
                    newNeeds[i] -= s[i];
            }
            if (flag){
                res = min(res, s[n] + shoppingOffers(price, special, newNeeds));
            }
        }
        
        // store result in cache
        cache[key] = res;
        return res;        
    }
private:
    unordered_map<int, int> cache;
};
