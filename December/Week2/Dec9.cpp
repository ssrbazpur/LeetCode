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

class BSTIterator
{
public:
    vector<int> inorder;
    int pointer;

    BSTIterator(TreeNode *root)
    {
        pointer = 0;
        assign(root);
    }

    //TC:O(N) || SC:O(N)
    void assign(TreeNode *root)
    {
        if (root == NULL)
            return;
        assign(root->left);
        inorder.push_back(root->val);
        assign(root->right);
    }

    //TC:O(1)
    int next()
    {
        if (hasNext())
            return inorder[pointer++];
        return -1;
    }

    //TC:O(1)
    bool hasNext()
    {
        return pointer < inorder.size();
    }
};

/*More Optimal

Time:O(1) | Space:O(h)

class BSTIterator {
private:
    stack<TreeNode*> st;
public:
    BSTIterator(TreeNode *root) {
        find_left(root);
    }

   
    bool hasNext() {
        if (st.empty())
            return false;
        return true;
    }

    int next() {
        TreeNode* top = st.top();
        st.pop();
        if (top->right != NULL)
            find_left(top->right);
            
        return top->val;
    }
    
   
    void find_left(TreeNode* root)
    {
        TreeNode* p = root;
        while (p != NULL)
        {
            st.push(p);
            p = p->left;
        }
    }
};

*/

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */