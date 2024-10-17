/**
 * Definition for a binary tree node.
 * struct TreeNode 
 {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution 
{
    int checkBalance(TreeNode* node)
    {
        if (node == NULL)
        {
            return 0;
        }

        int lh = checkBalance(node -> left);
        if (lh == -1)
        {
            return -1;
        }

        int rh = checkBalance(node -> right);
        if (rh == -1)
        {
            return -1;
        }

        if (abs(lh - rh) > 1)
        {
            return -1;
        }

        return max(lh, rh) + 1;


    }

    public:
        bool isBalanced(TreeNode* root) 
        {
            int res = checkBalance(root) != -1;
            return res;
        }
};
