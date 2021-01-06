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

//Time:O(N) | Space:O(N)
class Solution
{
public:
    ListNode *swapPairs(ListNode *head)
    {

        if (head == NULL || head->next == NULL)
        {
            return head;
        }
        cout << head->val;

        ListNode *f = head;
        ListNode *s = head->next;
        ListNode *t = head->next->next;

        s->next = f;
        f->next = swapPairs(t);

        // ListNode *p=head->next->next;
        // head->next->next=head;
        // head->next=swapPairs(p);

        return s;
    }
};