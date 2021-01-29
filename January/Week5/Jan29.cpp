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

struct Point
{
    int x;
    int y;
    int value;
};

class myComparator
{

public:
    int operator()(const Point &p1, const Point &p2)
    {
        if (p1.x != p2.x)
        {
            return p1.x > p2.x;
        }
        else
        {
            if (p1.y == p2.y)
            {
                return p1.value > p2.value;
            }
            return p1.y > p2.y;
        }
        return false;
    }
};

class Solution
{
private:
    priority_queue<Point, vector<Point>, myComparator> queue;

public:
    void traverse(TreeNode *root, int x, int y)
    {
        if (root == NULL)
        {
            return;
        }

        Point p;
        p.value = root->val;
        p.x = x;
        p.y = y;
        queue.push(p);
        traverse(root->left, x - 1, y + 1);
        traverse(root->right, x + 1, y + 1);
    }

    //TC:O(N) | SC:O(N)
    vector<vector<int>> verticalTraversal(TreeNode *root)
    {
        if (root == NULL)
        {
            return vector<vector<int>>{};
        }
        traverse(root, 0, 0);

        vector<vector<int>> ans;
        int prev = INT_MIN;
        while (!queue.empty())
        {
            Point p = queue.top();
            queue.pop();
            int nodeValue = p.value;
            int xValue = p.x;
            int yValue = p.y;
            if (xValue == prev)
            {
                ans[ans.size() - 1].push_back(nodeValue);
            }
            else
            {
                prev = xValue;
                vector<int> temp;
                temp.push_back(nodeValue);
                ans.push_back(temp);
            }
        }
        return ans;
    }
};