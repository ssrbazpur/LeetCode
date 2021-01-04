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

//Time:O(n) | Space:O(d) In worst case d is the depth of the tree.
class Solution
{
public:
    bool helper(TreeNode *root, long left, long right)
    {

        if (root == NULL)
            return true;
        if (root != NULL && root->val <= left)
            return false;
        if (root != NULL && root->val >= right)
            return false;
        bool left1 = helper(root->left, left, root->val);
        bool right1 = helper(root->right, root->val, right);
        return left1 && right1;
    }

    bool isValidBST(TreeNode *root)
    {
        return helper(root, LONG_MIN, LONG_MAX);
    }
};