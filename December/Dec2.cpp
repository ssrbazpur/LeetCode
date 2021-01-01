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

//Reservoir Sampling
//The rand() function is used in C/C++ to generate random numbers in the range [0, RAND_MAX).
//Time:O(n) | Space:O(1)

class Solution
{
public:
    ListNode *head = NULL;

    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode *head)
    {
        this->head = head;
    }

    /** Returns a random node's value. */
    int getRandom()
    {
        int res = -1;
        ListNode *node = head;
        int n = 1;
        while (node != NULL)
        {
            if (rand() % n == 0)
                res = node->val;
            node = node->next;
            n++;
        }
        return res;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */