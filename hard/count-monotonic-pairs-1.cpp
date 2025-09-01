const int MOD = 1000000007;

// T: O(50 * 50 * n)
// S: O(n) (Recursion stack)
int solve(vector<int>& nums, int idx, int p1, int p2) {
        if (idx == nums.size()) return 1;

        int counts = 0;
        for (int i = p1; i <= nums[idx]; i++) {
            if (nums[idx] - i <= p2) counts += solve(nums, idx+1, i, nums[idx] - i);
        }

        return counts;
}


// T: O(51 * 51 * 51 * n) = O(51^3 * n)
// S: O(51 * 51 * n) + O(n) (Recursion stack)
int solve(vector<int>& nums, int idx, int p1, int p2, vector<vector<vector<int>>> &dp) {
        if (idx == nums.size()) return 1;
        if (p2 != INT_MAX && dp[idx][p1][p2] != -1) return dp[idx][p1][p2];

        int counts = 0;
        for (int i = p1; i <= nums[idx]; i++) {
            if (nums[idx] - i <= p2) {
                counts = (counts + solve(nums, idx+1, i, nums[idx] - i, dp)) % MOD;
            }
        }

        if (p2 == INT_MAX) return (int)counts;
        return dp[idx][p1][p2] = (int)counts;
}


// Optimal solution
// TODO
