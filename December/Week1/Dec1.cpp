//Maximum Depth of Binary Tree

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
//Time Complexity: O(N) | Space:O(d) where N is the number of nodes and d is the depth of the tree.
class Solution
{
public:
    int maxDepth(TreeNode *root)
    {
        //Base Case
        if (root == NULL)
            return 0;
        //Recursive
        int left = maxDepth(root->left);
        int right = maxDepth(root->right);
        return max(left, right) + 1;
    }
};