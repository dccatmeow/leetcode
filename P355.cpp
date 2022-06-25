class Twitter {

public:
    using pii = pair<int, int>;
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        post[userId].emplace_back(pii(t, tweetId));
        t++;
    }
    
    vector<int> getNewsFeed(int userId) {
        auto comparator = [](pii x1, pii x2){
            return x1.first < x2.first;
        };
        priority_queue<pii, vector<pii>, decltype(comparator)> q(comparator);
        for(auto i:post[userId]){
            q.push(i);
        }
        for (auto i: followM[userId]){
            for (auto j: post[i]){
                q.push(j);
            }
        }
        vector<int> res;
        for (int i=0; i<10;++i){
            if (!q.empty()){
                res.push_back(q.top().second);
            }else{
                break;
            }
            q.pop();
        }
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        if (followerId!=followeeId){
            followM[followerId].insert(followeeId);
        }
    }
    
    void unfollow(int followerId, int followeeId) {
        followM[followerId].erase(followeeId);
    }
private:
    // map user to his/her follower
    unordered_map<int, set<int>> followM;
    // map user to pii of time and tweet ID
    unordered_map<int, vector<pii>> post;
    // time
    int t = 0;
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */
