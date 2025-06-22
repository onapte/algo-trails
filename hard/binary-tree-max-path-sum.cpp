#include <bits/stdc++.h>
using namespace std;


// T: O(n), S: O(1) + O(n) -> recursion call stack
int solve(TreeNode *node, int &sum)
{
    if (node == nullptr)
        return 0;

    int leftSum = max(0, solve(node->left, sum));
    int rightSum = max(0, solve(node->right, sum));

    sum = max(sum, leftSum + rightSum + node->val);

    return max(leftSum, rightSum) + node->val;
}