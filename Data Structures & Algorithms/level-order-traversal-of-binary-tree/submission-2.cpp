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
    vector<vector<int>> levelOrder(TreeNode* root)
    {
        vector<vector<int>> res;
        queue<TreeNode*> q;

        if(!root) return {};
        q.push(root);
        while(!q.empty())
        {
            int n = q.size();
            vector<int> temp;
            for(int i = 0; i < n; i++)
            {
                auto p = q.front(); q.pop();
                if(p->left) q.push(p->left);
                if(p->right) q.push(p->right);
                temp.push_back(p->val);
            }
            res.push_back(temp);
        }
        return res;
    }
};
