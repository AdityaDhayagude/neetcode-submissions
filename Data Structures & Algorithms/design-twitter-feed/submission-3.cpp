class Twitter {

    // This shall hold TimeStamps;
    int timeStamp = 0;

    //Store tweets : tweets are recognised by user and have a timeStamp followed by a unique id

    // Why store a timeStamp, beacause while unique id doesn't mean that it will be in ascening order and wouldn't be jumbled that is why a time stamp gives linearity 

    unordered_map<int, vector<pair<int, int>>> tweets;

    // Followee Id -> Each unique user can have certain followers
    // We use set as it guarantees no dulpication and fatser finding 
    unordered_map<int, unordered_set<int>> following;


public:
    Twitter() {}
    
    void postTweet(int userId, int tweetId) {
        //This bascially pushed the unique tweet by a specific user in tweets section
        tweets[userId].push_back({timeStamp++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        // Inorder to get everythig and arrange them inorder of receny we can initate a maxHeap 

        priority_queue<pair<int, int>> maxHeap;

        // Add user's own tweets
        for(auto& tweet : tweets[userId]) maxHeap.push(tweet);

        //Add tweets from everyone user follows 

        for(int followeeId : following[userId]){
            if(followeeId == userId) continue;
            for(auto tweet : tweets[followeeId]){
                maxHeap.push(tweet);
            }
        }

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
