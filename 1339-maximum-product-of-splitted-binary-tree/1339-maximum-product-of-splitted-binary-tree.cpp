/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    long long total = 0, ans = 0;
    const int MOD = 1e9 + 7;

    int maxProduct(TreeNode* root) {
        totalSum(root);
        subTreeSum(root);
        return ans % MOD;
    }

    void totalSum(TreeNode* root) {
        if (!root) return;
        total += root->val;
        totalSum(root->left);
        totalSum(root->right);
    }

    long long subTreeSum(TreeNode* root) {
        if (!root) return 0;

        long long left = subTreeSum(root->left);
        long long right = subTreeSum(root->right);

        long long curr = left + right + root->val;
        ans = max(ans, curr * (total - curr));

        return curr;
    }
};
