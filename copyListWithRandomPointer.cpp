/*
// Definition for a Node.
class Node 
{
    public:
        int val;
        Node* next;
        Node* random;
        
        Node(int _val) {
            val = _val;
            next = NULL;
            random = NULL;
        }
};
*/

class Solution 
{
    public:
        Node* copyRandomList(Node* head) 
        {

            if (!head)
            {
                return head;
            }
            
            Node* temp = head, *res = new Node(-1), *dummy = new Node(-1);

            while (temp != NULL)
            {
                Node* copy = new Node(temp -> val);
                copy -> next = temp -> next;
                temp -> next = copy;
                temp = temp -> next -> next;
            }

            temp = head;

            while (temp != NULL)
            {
                Node* copy = temp -> next;

                if (temp -> random == NULL)
                {
                    copy -> random = NULL;
                }
                else 
                {
                    copy -> random = temp -> random -> next;
                }

                temp = temp -> next -> next;
            }

            temp = head;
            dummy -> next = temp -> next;

            while (temp != NULL)
            {
                res -> next = temp -> next;
                temp -> next = temp -> next -> next;
                temp  = temp -> next;
                res = res -> next;
            }

            return dummy -> next;
        }
};
