/**
 * Definition for a binary tree node.
 * struct TreeNode {
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
    void postorderRecursive(TreeNode* node, vector<int> &res)
    {
        if (node == NULL)
        {
            return;
        }

        postorderRecursive(node -> left, res);
        postorderRecursive(node -> right, res);
        res.push_back(node -> val);
    }

    void postorderIterative(TreeNode* node, vector<int> &res)
    {
         if (node == NULL)
        {
            return;
        }

        stack<TreeNode*> st1, st2;

        st1.push(node);

        while (!st1.empty())
        {
            TreeNode* curr = st1.top();
            st1.pop();

            st2.push(curr);

            if (curr->left)
            {
                st1.push(curr->left);
            }
            if (curr->right)
            {
                st1.push(curr->right);
            }
        }

        while (!st2.empty())
        {
            res.push_back(st2.top()->val);
            st2.pop();
        }
    }

    public:
        vector<int> postorderTraversal(TreeNode* root) 
        {
            vector<int> res;

            postorderRecursive(root, res);
            
            return res;
        }
};
