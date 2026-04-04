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
    int kthSmallest(TreeNode* root, int k) {
        priority_queue<int> pq;
        inOrder(root, pq, k);
        return pq.top();
    }

    void inOrder(TreeNode* root, priority_queue<int>& pq, int k)
    {
        if(!root) return;

        inOrder(root->left, pq, k);

        pq.push(root->val);
        if(pq.size() > k) pq.pop();

        inOrder(root->right, pq, k);
    }
};
