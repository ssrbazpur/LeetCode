/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

/*
TC:O(N)
SC:O(N)
*/
class Solution
{
public:
    Node *connect(Node *root)
    {
        if (root == NULL)
            return NULL;

        queue<Node *> hm;
        hm.push(root);

        while (!hm.empty())
        {

            int len = hm.size();

            while (len-- > 0)
            {
                Node *temp = hm.front();
                hm.pop();

                if (len == 0)
                    temp->next = NULL;
                else
                {
                    temp->next = hm.front();
                }
                if (temp->left != NULL)
                    hm.push(temp->left);
                if (temp->right != NULL)
                    hm.push(temp->right);
            }
        }

        //         queue<pair<Node *,int>> hm;
        //         pair<Node *,int> root1;
        //         int level=1;
        //         root1.first=root;
        //         root1.second=level;
        //         hm.push(make_pair(root,level));

        //         while(!hm.empty()){
        //             pair<Node *,int> temp=hm.front();
        //             Node *node=temp.first;
        //             int level=temp.second;
        //             hm.pop();

        //             level++;
        //             if(node->left!=NULL) hm.push(make_pair(node->left,level));
        //             if(node->right!=NULL) hm.push(make_pair(node->right,level));

        //             if(hm.empty()) node->next=NULL;
        //             else{

        //                 if(hm.front().second==level-1) node->next=hm.front().first;
        //                 else node->next==NULL;
        //             }

        //         }
        return root;
    }
};