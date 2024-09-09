/**
 * Definition for singly-linked list.
 * struct ListNode 
 {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution 
{
    public:
        ListNode* reverseKGroup(ListNode* head, int k) 
        {
            if (head == NULL || k == 1)
            {
                return head;
            }

            ListNode* temp = new ListNode(0);
            temp -> next = head;

            ListNode* curr = temp, *pre = temp, *next = temp;
            int count = 0;

            while (curr -> next != NULL)
            {
                curr = curr -> next;
                count++;
            }

            while (count >= k)
            {
                curr = pre -> next;
                next = curr -> next;

                for (int i = 1; i < k; i++)
                {
                    curr -> next = next -> next;
                    next -> next = pre -> next;
                    pre -> next = next;
                    next = curr -> next;
                }

                pre = curr;
                count -= k;
            }

            return temp -> next;
        }
};
