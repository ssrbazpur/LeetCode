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
//SPace:O(d) | Time:O(n)
class Solution
{
public:
    int dfs(TreeNode *node, int depth, bool &ans)
    {
        //if(ans==false) return depth;
        if (node == NULL)
            return depth;
        int left = dfs(node->left, depth + 1, ans);
        int right = dfs(node->right, depth + 1, ans);
        if (abs(left - right) > 1)
            ans = false;
        return max(left, right);
    }

    bool isBalanced(TreeNode *root)
    {
        int depth = 0;
        bool ans = true;
        int d = dfs(root, depth, ans);
        return ans;
    }
};