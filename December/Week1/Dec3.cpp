//Increasing Order Search Tree
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

//Time:O(n) | Space:O(n)
class Solution
{

private:
    TreeNode *ans;

public:
    void inOrderTraversal(TreeNode *root)
    {
        if (root == NULL)
            return;
        inOrderTraversal(root->left);
        root->left = NULL;
        ans->right = root;
        ans = root;
        inOrderTraversal(root->right);
    }

    TreeNode *increasingBST(TreeNode *root)
    {
        TreeNode *temp = new TreeNode(0);
        ans = temp;
        inOrderTraversal(root);
        return temp->right;
    }

    //     void inOrderTraversal(TreeNode *root,vector<int> &inOrder){
    //         if(root==NULL) return;
    //         inOrderTraversal(root->left,inOrder);
    //         inOrder.push_back(root->val);
    //         inOrderTraversal(root->right,inOrder);
    //     }

    //     TreeNode* increasingBST(TreeNode* root) {
    //         vector<int> inOrder;
    //         inOrderTraversal(root,inOrder);
    //         TreeNode *rootNew=new TreeNode(inOrder[0]);
    //         TreeNode *temp=rootNew;
    //         for(int i=1;i<inOrder.size();i++){
    //             temp->right=new TreeNode(inOrder[i]);
    //             temp=temp->right;
    //         }
    //         return rootNew;
    //     }
};