class Solution {
public:
    // pair.first  -> node (answer)
    // pair.second -> depth
    pair<TreeNode*, int> dfs(TreeNode* root) {
        if (!root)
            return {nullptr, 0};

        auto L = dfs(root->left);
        auto R = dfs(root->right);

        if (L.second == R.second)
            return {root, L.second + 1};
        else if (L.second > R.second)
            return {L.first, L.second + 1};
        else
            return {R.first, R.second + 1};
    }

    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        return dfs(root).first;
    }
};
