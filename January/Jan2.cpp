/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/*
Time Complexity: O(N)
Space Complexity: O(N)
*/

class Solution
{
private:
    // TreeNode *ans=NULL;
public:
    //INORDER Traversal
    //     void dfs(TreeNode* original, TreeNode* cloned, TreeNode* target){
    //         if(original==NULL){
    //             return;
    //         }
    //         dfs(original->left,cloned->left,target);
    //         if(original==target){
    //             ans=cloned;
    //         }
    //         dfs(original->right,cloned->right,target);
    //     }

    TreeNode *getTargetCopy(TreeNode *original, TreeNode *cloned, TreeNode *target)
    {
        // dfs(original,cloned,target);
        // return ans;

        //Second Method
        if (original == NULL)
            return NULL;

        if (original == target)
        {
            return cloned;
        }

        TreeNode *left = getTargetCopy(original->left, cloned->left, target);
        if (left != NULL)
            return left;
        TreeNode *right = getTargetCopy(original->right, cloned->right, target);
        return right;
    }
};