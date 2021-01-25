/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

//[1,1,2,3,4]
//mid=1
//[1,1,2] [3,4]
//[1,1] [2]

class Solution
{
public:
    void mergeSort(vector<ListNode *> &lists, int l, int r)
    {
        if (l < r)
        {
            int mid = (l + r) / 2;
            mergeSort(lists, l, mid);
            mergeSort(lists, mid + 1, r);
            merge(lists, l, r, mid);
        }
    }

    void merge(vector<ListNode *> &lists, int start, int end, int mid)
    {

        ListNode *p1 = lists[start];
        ListNode *p2 = lists[mid + 1];
        ListNode *dummyNode = new ListNode(-1);
        ListNode *track = dummyNode;

        while (p1 != NULL && p2 != NULL)
        {
            if (p1->val <= p2->val)
            {
                track->next = p1;
                track = p1;
                p1 = p1->next;
            }
            else
            {
                track->next = p2;
                track = p2;
                p2 = p2->next;
            }
        }

        while (p1 != NULL)
        {

            track->next = p1;
            track = p1;
            p1 = p1->next;
        }

        while (p2 != NULL)
        {
            track->next = p2;
            track = p2;
            p2 = p2->next;
        }
        lists[start] = dummyNode->next;
        lists[mid + 1] = NULL;
    }

    ListNode *mergeKLists(vector<ListNode *> &lists)
    {

        // ListNode *dummyNode=new ListNode(-1);
        mergeSort(lists, 0, lists.size() - 1);
        return lists.size() > 0 ? lists[0] : NULL;
    }
};

//Second Answer (Min-Heap)

// class myComparator{

//     public:
//     int operator()(ListNode *p1,ListNode *p2)
//     {
//         return p1->val > p2->val;
//     }
// };

//Watch Heap .

// k is the number of list
//Time Complexity: O(n*k*logk)
//Space: O(k)
// class Solution {
// public:

//     ListNode* mergeKLists(vector<ListNode*>& lists) {
//         priority_queue<ListNode *,vector<ListNode *>,myComparator> q;

//         for(int i=0;i<lists.size();i++){
//             if(lists[i]!=NULL) q.push(lists[i]);
//         }

//         ListNode *dummy=new ListNode(-1);
//         ListNode *ref=dummy;
//         // r m w a
//         while(!q.empty()){

//             ListNode *node=q.top();
//             q.pop();

//             ref->next=node;
//             ref=ref->next;
//             ListNode *nodeNext=node->next;
//             node->next=NULL;

//             if(nodeNext!=NULL){
//                 q.push(nodeNext);
//             }

//         }

//         return dummy->next;
//     }
// };