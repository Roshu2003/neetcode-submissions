class Twitter {
public:
    int time;
    unordered_map<int,vector<pair<int,int>>> tweet;
    unordered_map<int,unordered_set<int>> followMp;
    Twitter() {
        time = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweet[userId].push_back({time++,tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<tuple<int,int,int>> pq;
        followMp[userId].insert(userId);
        for(auto it : followMp[userId]){
            if(tweet[it].empty())continue;
            int index = tweet[it].size() - 1;
            int t = tweet[it][index].first;
            pq.push({t,it,index});
        }
        vector<int> ans;
        while(pq.size() > 0 && ans.size() < 10){
            auto [t,user,index] = pq.top();
            pq.pop();
            ans.push_back(tweet[user][index].second);
            if(index > 0){
                int prevIndex = index - 1;
                int prevTime =  tweet[user][prevIndex].first;
                pq.push({prevTime,user,prevIndex});
            }
        }
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        if(followerId != followeeId){
            followMp[followerId].insert(followeeId);
        }
    }
    
    void unfollow(int followerId, int followeeId) {
        followMp[followerId].erase(followeeId);
    }
};
