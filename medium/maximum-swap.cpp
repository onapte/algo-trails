// TC: O(n.logn)
// SC: O(n)

int maximumSwap(int num) {
        if (num < 10) return num;

        vector<int> digits;

        auto cmp = [](const pair<int, int> &a, const pair<int, int> &b) {
            if (a.first == b.first) return a.second < b.second;
            return a.first < b.first;
        };

        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);
        while (num > 0) {
            digits.push_back(num % 10);
            num /= 10;
        }

        reverse(digits.begin(), digits.end());

        for (int i = 0; i < digits.size(); i++) {
            pq.push(make_pair(digits[i], i));
        }

        int ans = 0;
        for (int i = 0; i < digits.size(); i++) {
            while (pq.size() > 0 && pq.top().second < i) {
                pq.pop();
            }

            if (pq.size() > 0 && pq.top().first > digits[i]) {
                digits[pq.top().second] = digits[i];
                digits[i] = pq.top().first;
                break;
            }
        }

        for (int i = 0; i < digits.size(); i++) {
            cout << digits[i] << " ";
            ans = ans * 10 + digits[i];
        }

        return ans;
}


// TC: O(n)
// SC: O(n)

int maximumSwap(int num) {
        if (num < 10) return num;

        vector<int> digits;

        while (num > 0) {
            digits.push_back(num % 10);
            num /= 10;
        }

        vector<int> lastIndex(10, -1);

        reverse(digits.begin(), digits.end());

        for (int i = 0; i < digits.size(); i++) {
            lastIndex[digits[i]] = i;
        }

        int ans = 0;
        for (int i = 0; i < digits.size(); i++) {
            int digit = digits[i];
            bool swapped = false;

            for (int j = 9; j > digit; j--) {
                if (lastIndex[j] > i) {
                    int idx = lastIndex[j];
                    digits[idx] = digits[i];
                    digits[i] = j;
                    swapped = true;
                    break;
                }
            }

            if (swapped) break;
        }

        for (int i = 0; i < digits.size(); i++) {
            ans = ans * 10 + digits[i];
        }

        return ans;
}
