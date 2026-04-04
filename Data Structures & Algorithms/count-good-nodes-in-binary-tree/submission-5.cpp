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
    int goodNodes(TreeNode* root) {
        return dfs(root, INT_MIN);
    }

    int dfs(TreeNode* root, int maxVar)
    {
        if(!root) return 0;

        int res = (root->val >= maxVar) ? 1 : 0;
        maxVar = max(root->val, maxVar);
        res += dfs(root->left, maxVar);
        res += dfs(root->right, maxVar);
        return res;
    }
};
