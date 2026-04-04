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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        queue<pair<TreeNode*, int>> q;
        if(root != nullptr)
        {
            q.push({root, 0});
        }
        while(!q.empty())
        {
            auto p = q.front(); q.pop();
            int level = p.second;
            if(res.size() == level)
            {
                res.push_back({});
            }
            res[level].push_back(p.first->val);
            if(p.first->left != nullptr) q.push({p.first->left, level+1});
            if(p.first->right != nullptr) q.push({p.first->right, level+1});
        }
        return res;
    }
};
