class Twitter {
    //Let's get a timeStamp

    int timeStamp = 0;

    //userId -> list of {timeStamp, tweetId}
    unordered_map<int, vector<pair<int, int>>> tweets;

    //followerId -> set of followeeIds
    unordered_map<int, unordered_set<int>> following;

public:
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {

        //Store tweets with current timeStamp, then increment it
        tweets[userId].push_back({timeStamp++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        // Max Heap : {timeStamp, tweetId}
        priority_queue<pair<int, int>> maxHeap;

        //add users own tweets
        for(auto& tweet:tweets[userId]) maxHeap.push(tweet);

        //Add tweets from everyone the user follows 
        for(int followeeId : following[userId]){
            if(followeeId == userId) continue;
            for(auto& tweet : tweets[followeeId]){
                maxHeap.push(tweet);
            }             

        }

        // GRAB top 10 recent tweets 
        vector<int> feed;
        while(!maxHeap.empty() && feed.size()<10){
            feed.push_back(maxHeap.top().second);
            maxHeap.pop();
        }

        return feed;

    }
    
    void follow(int followerId, int followeeId) {
        following[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
    }
};
