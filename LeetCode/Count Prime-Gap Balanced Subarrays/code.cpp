class Solution {
public:
    long long primeSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<bool> prime(50001, true);
        prime[0] = false;
        prime[1] = false;
        for (int i = 2; i * i <= 50000; i++) {
            if (prime[i]) {
                for (int j = i * i; j <= 50000; j += i) {
                    prime[j] = false;
                }
            }
        }
        vector<pair<int, int>> primes;
        for (int i = 0; i < n; i++) {
            if (prime[nums[i]]) {
                primes.push_back({nums[i], i});
            }
        }
        int p = primes.size();
        if (p < 2) {
            return 0;
        }
        multiset<int> st;
        int left = 0;
        long long ans = 0;
        for (int right = 0; right < p; right++) {
            st.insert(primes[right].first);
            while (*st.rbegin() - *st.begin() > k) {
                st.erase(st.find(primes[left].first));
                left++;
            }
            if (right - left + 1 < 2) {
                continue;
            }
            int previousPrimeIndex;
            if (left == 0) {
                previousPrimeIndex = -1;
            }
            else {
                previousPrimeIndex = primes[left - 1].second;
            }
            long long startChoices = primes[right - 1].second - previousPrimeIndex;
            long long endChoices;
            if (right + 1 < p) {
                endChoices = primes[right + 1].second - primes[right].second;
            }
            else {
                endChoices = n - primes[right].second;
            }
            ans += startChoices * endChoices;
        }
        return ans;
    }
};