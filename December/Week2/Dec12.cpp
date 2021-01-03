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

//1. If node depth of left and right are same then return node
//2. If right > left return right else return left

//Time:o(n)| Space:O(n)
class Solution
{
public:
    pair<int, TreeNode *> helper(TreeNode *node, int depth)
    {

        if (node == NULL)
            return {depth, NULL};
        pair<int, TreeNode *> left = helper(node->left, depth + 1);
        pair<int, TreeNode *> right = helper(node->right, depth + 1);

        if (left.first == right.first)
            return {max(left.first, right.first), node};
        if (left.first > right.first)
            return {max(left.first, right.first), left.second};

        return {max(left.first, right.first), right.second};
    }

    TreeNode *subtreeWithAllDeepest(TreeNode *root)
    {

        pair<int, TreeNode *> ans = helper(root, 0);
        return ans.second;
    }
};