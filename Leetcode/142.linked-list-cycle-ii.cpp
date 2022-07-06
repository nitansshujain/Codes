/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        ListNode *sp = head;
        ListNode *fp = head; // fp = head->next will give TLE.
        while (fp and fp->next)
        {
            sp = sp->next;
            fp = fp->next->next;
            if (sp == fp)
            {
                sp = head;
                while (sp != fp)
                {
                    sp = sp->next;
                    fp = fp->next;
                }
                return sp;
            }
        }

        return nullptr;
    }
};