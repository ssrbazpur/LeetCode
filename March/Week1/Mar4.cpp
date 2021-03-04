/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//L1 L2 DIFF=|L1-L2|
class Solution
{
public:
    int getLength(ListNode *node)
    {
        int len = 0;
        while (node != NULL)
        {
            node = node->next;
            len++;
        }
        return len;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {

        int len1 = getLength(headA);
        int len2 = getLength(headB);

        int diff = abs(len1 - len2);
        if (len1 > len2)
        {
            while (diff > 0)
            {
                headA = headA->next;
                diff--;
            }
        }
        else if (len2 > len1)
        {
            while (diff > 0)
            {
                headB = headB->next;
                diff--;
            }
        }

        while (headA != NULL && headA != headB && headB != NULL)
        {
            headA = headA->next;
            headB = headB->next;
        }

        return headA;
    }
};