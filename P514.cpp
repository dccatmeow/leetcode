/*
In the video game Fallout 4, the quest "Road to Freedom" requires players to reach a metal dial called the "Freedom Trail Ring" 
and use the dial to spell a specific keyword to open the door.

Given a string ring that represents the code engraved on the outer ring and another string key that represents the keyword 
that needs to be spelled, return the minimum number of steps to spell all the characters in the keyword.

Input: ring = "godding", key = "gd"
Output: 4
*/

class Solution {
public:
    int findRotateSteps(string ring, string key) {
        int m = ring.size();
        int n = key.size();
        std::vector<std::vector<int>> mp(26, vector<int>());
        for (int i=0; i<m; ++i){
            mp[ring[i]-'a'].push_back(i);
        }
        
        // dp[i][j] is the min step move from key[j] to key[n-1]
        // when currently ring is at position i
        vector<vector<int>> dp(m, vector<int>(n+1, INT_MAX));
        for (int i=0; i<m;++i){
            dp[i][n] = 0;
        }
        int dist;
        // loop from the end of key to the beginning
        for (int j=n-1; j>=0; --j){
            for (int i=0; i<m; ++i){
                if (ring[i]==key[j]){
                    // if key is matched with current position
                    dp[i][j] = dp[i][j+1];
                }else{
                    // 
                    for (auto e:mp[key[j]-'a']){
                        // iterate through all the positions of key[j] in the ring
                        // to find the minimum move from e to i
                        // in clockwise and counter-clockwise
                        dist = min(abs(e-i), m-abs(e-i));
                        dp[i][j] = min(dp[i][j], dist+dp[e][j+1]);
                    }
                } 
            }
        }
        // n is the number of times of pressing button
        return dp[0][0]+n;
    }
};
