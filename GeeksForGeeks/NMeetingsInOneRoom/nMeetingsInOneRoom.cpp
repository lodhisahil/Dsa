class Solution {
public:
    vector<int> maxMeetings(vector<int> &s, vector<int> &f) {

        vector<tuple<int, int, int>> meetings;
        // {endingTime, startingTime, position}

        for(int i = 0; i < s.size(); i++) {
            meetings.push_back({f[i], s[i], i + 1});
        }

        sort(meetings.begin(), meetings.end(),
            [](auto &a, auto &b) {

                if(get<0>(a) != get<0>(b))
                    return get<0>(a) < get<0>(b);

                return get<2>(a) < get<2>(b);
            });

        vector<int> ans;

        int endTime = get<0>(meetings[0]);
        ans.push_back(get<2>(meetings[0]));

        for(int i = 1; i < meetings.size(); i++) {

            int startTime = get<1>(meetings[i]);

            if(startTime > endTime) {
                ans.push_back(get<2>(meetings[i]));
                endTime = get<0>(meetings[i]);
            }
        }

        sort(ans.begin(), ans.end());

        return ans;
    }
};