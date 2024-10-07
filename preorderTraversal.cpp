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
    void preorderRecursive(TreeNode* node, vector<int> &res)
    {
        if (!node)
            return;

        res.push_back(node -> val);
        preorderRecursive(node -> left, res);
        preorderRecursive(node -> right, res);
    }

    void preorderIterative(TreeNode* node, vector<int> res)
    {

        if (!node)
            return;

        stack<TreeNode*> st;
        st.push(node);

        while (!st.empty())
        {
            TreeNode* top = st.top();
            res.push_back(top -> val);
            st.pop();

            if (top -> right)
            {
                st.push(top -> right);
            }

            if (top -> left)
            {
                st.push(top -> left);
            }
        }
    }

    void preorderMorris(TreeNode* node, vector<int> &res)
    {
        TreeNode* curr = node;
        while (curr != NULL)
        {
            if (curr -> left == NULL)
            {
                res.push_back(curr -> val);
                curr = curr -> right;
            }
            else
            {
                TreeNode* temp = curr -> left;
                while (temp -> right && temp -> right != curr)
                {
                    temp = temp -> right;
                }
                
                if (temp -> right == NULL)
                {
                    temp -> right = curr;
                    res.push_back(curr -> val);
                    curr = curr -> left;
                }
                else
                {
                    temp -> right = NULL;
                    curr = curr -> right;
                }
            }
        }
    }


    public:
        vector<int> preorderTraversal(TreeNode* root) 
        {
            vector<int> res;

            preorderMorris(root, res);

            return res;
        }
};
