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

/*
Time:O(max(m,n))
Space:O(max(m,n))

*/
class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {

        ListNode *head = new ListNode(-1);
        ListNode *track = head;
        int carry = 0;
        while (l1 != NULL || l2 != NULL)
        {
            int sum = carry;
            if (l1 != NULL)
            {
                sum = sum + l1->val;
                l1 = l1->next;
            }
            if (l2 != NULL)
            {
                sum = sum + l2->val;
                l2 = l2->next;
            }
            int value = sum % 10;
            track->next = new ListNode(value);
            track = track->next;
            carry = sum / 10;
        }
        if (carry == 1)
        {
            track->next = new ListNode(carry);
        }

        return head->next;
    }
};