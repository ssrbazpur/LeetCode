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
class Solution {
public:
    
    void dfs(TreeNode *node,int &depth,int x,int realdepth,TreeNode *parent,int &real){
        
        if(node==NULL) return ;
        //
        cout<<realdepth;
        cout<<node->val;
        cout<<endl;

        if(node->val==x){
            cout<<"hello";
            depth=realdepth;
            real=parent!=NULL?parent->val:0;
                         return;
                        }
        realdepth=realdepth+1;
        dfs(node->left,depth,x,realdepth,node,real);
        dfs(node->right,depth,x,realdepth,node,real);
 
    }
    bool isCousins(TreeNode* root, int x, int y) {
        int d=0;
        TreeNode *parent=NULL;
        int real=0;
        dfs(root,d,x,0,parent,real);
        cout<<d;
        cout<<real;
        
        int d2=0;
        TreeNode *parent2=NULL;
        int real2=0;
        dfs(root,d2,y,0,parent2,real2);
        cout<<d2;
        cout<<real2;
        return d2==d ? (real!=real2 ? true :false) :false;
        
    }
};
