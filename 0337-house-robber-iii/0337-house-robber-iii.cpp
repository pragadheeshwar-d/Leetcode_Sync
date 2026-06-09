class Solution {
public:
    unordered_map<TreeNode*, int> dp;

    int rob(TreeNode* root) {
        if (!root) 
            return 0;
        if (dp.count(root)) 
            return dp[root];

        int rob_current = root->val;
        if (root->left) {
            rob_current += rob(root->left->left) + rob(root->left->right);
        }
        if (root->right) {
            rob_current += rob(root->right->left) + rob(root->right->right);
        }

        int skip_current = rob(root->left) + rob(root->right);

        return dp[root] = max(rob_current, skip_current);
    }
};