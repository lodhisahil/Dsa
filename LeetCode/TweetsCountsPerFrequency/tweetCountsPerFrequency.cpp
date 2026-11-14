class TweetCounts {
    unordered_map<string, vector<int>> mp;
public:
    TweetCounts() {

    }
    
    void recordTweet(string tweetName, int time) {
        mp[tweetName].push_back(time);
    }
    vector<int> getTweetCountsPerFrequency(string freq, string tweetName, int startTime, int endTime) {
        int chunkSize;
        if (freq == "minute") {
            chunkSize = 60;
        }
        else if (freq == "hour") {
            chunkSize = 3600;
        }
        else {
            chunkSize = 86400;
        }
        vector<int> ans;
        vector<int> &times = mp[tweetName];
        sort(times.begin(), times.end());
        for (int start = startTime; start <= endTime; start += chunkSize) {
            int end = min(start + chunkSize - 1, endTime);
            auto left = lower_bound(times.begin(), times.end(), start);
            auto right = upper_bound(times.begin(), times.end(), end);
            ans.push_back(right - left);
        }
        return ans;
    }
};