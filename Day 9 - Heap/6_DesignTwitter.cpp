/*
Design a simplified version of Twitter where users can post tweets, follow/unfollow another user, and is able to see the 10 most recent tweets in the user's news feed.

Implement the Twitter class:

Twitter() Initializes your twitter object.
void postTweet(int userId, int tweetId) Composes a new tweet with ID tweetId by the user userId. Each call to this function will be made with a unique tweetId.
List<Integer> getNewsFeed(int userId) Retrieves the 10 most recent tweet IDs in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user themself. Tweets must be ordered from most recent to least recent.
void follow(int followerId, int followeeId) The user with ID followerId started following the user with ID followeeId.
void unfollow(int followerId, int followeeId) The user with ID followerId started unfollowing the user with ID followeeId.

https://leetcode.com/problems/design-twitter/description/
*/

class Twitter {
public:
    Twitter() {
        timestamp = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        // Check if the user exists, if not, create a new user.
        if (users.find(userId) == users.end()) {
            users[userId] = std::make_pair(std::unordered_set<int>(), std::vector<std::pair<int, int>>());
        }
        
        // Add the tweet to the user's tweets.
        users[userId].second.push_back(std::make_pair(timestamp++, tweetId));
    }
    
    std::vector<int> getNewsFeed(int userId) {
        std::vector<int> newsFeed;
        if (users.find(userId) == users.end()) {
            return newsFeed; // User doesn't exist.
        }
        
        // Create a merged timeline of the user and the users they follow.
        std::set<std::pair<int, int>> timeline;
        timeline.insert(users[userId].second.begin(), users[userId].second.end());
        
        for (const int& followeeId : users[userId].first) {
            std::vector<std::pair<int, int>>& followeeTweets = users[followeeId].second;
            timeline.insert(followeeTweets.begin(), followeeTweets.end());
        }
        
        // Retrieve the latest 10 tweets.
        int count = 0;
        for (auto it = timeline.rbegin(); it != timeline.rend() && count < 10; ++it) {
            newsFeed.push_back(it->second);
            count++;
        }
        
        return newsFeed;
    }
    
    void follow(int followerId, int followeeId) {
        if (followerId == followeeId) {
            return; // A user cannot follow themself.
        }
        // Check if the users exist and add the followee to the follower's following list.
        users[followerId].first.insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if (followerId == followeeId) {
            return; // A user cannot unfollow themself.
        }
        // Check if the users exist and remove the followee from the follower's following list.
        users[followerId].first.erase(followeeId);
    }

private:
    int timestamp;
    std::unordered_map<int, std::pair<std::unordered_set<int>, std::vector<std::pair<int, int>>> > users;
};