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
class Solution
{
public:
    void helper(TreeNode *node, int &tracker)
    {
        if (node == NULL)
        {
            return;
        }

        helper(node->right, tracker);
        tracker = node->val + tracker;
        node->val = tracker;
        helper(node->left, tracker);
    }

    //TC:O(N) | Space:O(d)
    TreeNode *convertBST(TreeNode *root)
    {
        int start = 0;
        helper(root, start);
        return root;
    }
};