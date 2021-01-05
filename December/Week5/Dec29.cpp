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

//Space:O(d) | Time:O(n)
class Solution
{
private:
    int ans;

public:
    bool isPalindrome(vector<int> store)
    {
        bool odd = false;
        for (int i = 1; i < store.size(); i++)
        {
            if (store[i] % 2 != 0)
            {
                if (odd == true)
                    return false;
                odd = true;
            }
        }
        return true;
    }

    void dfs(TreeNode *node, vector<int> store)
    {

        if (node == NULL)
            return;

        store[node->val]++;
        cout << node->val;

        if (node->left == NULL && node->right == NULL)
        {
            if (isPalindrome(store))
                ans++;
            return;
        }

        dfs(node->left, store);
        dfs(node->right, store);
        //store[node->val]--;
    }

    int pseudoPalindromicPaths(TreeNode *root)
    {
        ans = 0;
        vector<int> store(10, 0);
        dfs(root, store);
        return ans;
    }
};