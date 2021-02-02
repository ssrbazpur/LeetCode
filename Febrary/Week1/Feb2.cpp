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
    //TC:O(N) | SC:O(d)
    TreeNode *trimBST(TreeNode *root, int low, int high)
    {

        if (root == NULL)
        {
            return NULL;
        }

        TreeNode *leftTree = trimBST(root->left, low, high);
        TreeNode *rightTree = trimBST(root->right, low, high);

        root->left = leftTree;
        root->right = rightTree;

        if (root->val < low)
        {
            return rightTree;
        }
        else if (root->val > high)
        {
            return leftTree;
        }

        return root;
    }
};