bool solve(vector<int> &nums, int i, int sum, int target, vector<vector<int>> &dp) {
        if (i == nums.size()) {
            if (target/2 == sum) return true;
            return false;
        }

        if (dp[i][target-sum] != -1) return dp[i][target-sum];

        bool choose = solve(nums, i+1, sum + nums[i], target, dp);
        bool skip = solve(nums, i+1, sum, target, dp);

        return dp[i][target-sum] = choose || skip;
    }