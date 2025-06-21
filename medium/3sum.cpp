#include <bits/stdc++.h>
using namespace std;

typedef long long int L;

// Naive solution
// T: O(n^(2).logk), S: O(n^2)
// k is the number of unique pairs
vector<vector<int>> threeSum(vector<int> &nums)
{
    vector<vector<int>> ans;
    set<vector<int>> pairs;

    unordered_map<int, int> s;

    sort(nums.begin(), nums.end());
    for (int num : nums)
        s[num]++;

    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = i + 1; j < nums.size(); j++)
        {
            L sum = nums[j] + nums[i];

            if (-sum < nums[j])
                break;

            int target = -sum;
            vector<int> targetPair = {nums[i], nums[j], target};
            if (s.count(target) && !pairs.count(targetPair))
            {

                if (target == nums[i] || target == nums[j])
                {
                    if (nums[i] == nums[j] && s[nums[i]] < 3)
                        continue;
                    if (target == nums[i] && s[nums[i]] < 2)
                        continue;
                    if (target == nums[j] && s[nums[j]] < 2)
                        continue;
                }

                ans.push_back(targetPair);
                pairs.insert(targetPair);
            }
        }
    }

    return ans;
}

// Optimized
// T: O(n^2), S: O(k)
// k is the number of unique pairs
vector<vector<int>> threeSum(vector<int> &nums)
{
    vector<vector<int>> ans;

    sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size() - 2; i++)
    {
        if (i > 0 && nums[i] == nums[i - 1])
            continue;
        int j = i + 1, k = nums.size() - 1;

        L sum = nums[i] + nums[j] + nums[k];

        while (j < k)
        {
            L sum = nums[i] + nums[j] + nums[k];

            if (sum < 0)
                j++;
            else if (sum > 0)
                k--;
            else
            {
                ans.push_back({nums[i], nums[j], nums[k]});
                j++;
                while (j < k && nums[j] == nums[j - 1])
                    j++;
            }
        }
    }

    return ans;
}