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
class Solution {
public:
    void inorderRecursive(TreeNode* curr, vector<int> &res)
    {
        if (curr == NULL)
        {
            return;
        }

        inorderRecursive(curr -> left, res);
        res.push_back(curr -> val);
        inorderRecursive(curr -> right, res);
    }

   void inorderIterative(TreeNode* curr, vector<int> &res)
    {
        stack<TreeNode*> st;

        while (curr != NULL || !st.empty())
        {
            while (curr != NULL)
            {
                st.push(curr);
                curr = curr->left;
            }

            curr = st.top();
            st.pop();

            res.push_back(curr->val);

            curr = curr->right;
        }
    }

    void inorderMorris(TreeNode* node, vector<int> &res)
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
                    curr = curr -> left;
                }
                else
                {
                    temp -> right = NULL;
                    res.push_back(curr -> val);
                    curr = curr -> right;
                }
            }
        }
    }


    vector<int> inorderTraversal(TreeNode* root) 
    {

        vector<int> res;

        if (root == NULL)
        {
            return res;
        }

        inorderMorris(root, res);
        return res;
    }
};
