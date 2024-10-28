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
    int findMaxPath(TreeNode* curr, int &res)
    {
        if (curr == NULL)
        {
            return 0;
        }
        
    
        int left = max(0, findMaxPath(curr -> left, res));
        int right = max(0, findMaxPath(curr -> right, res));

        res = max(res, (left + right + curr -> val));
        return curr -> val + max(left, right);
    }

    public:
        int maxPathSum(TreeNode* root) 
        {
            int res = INT_MIN;
            findMaxPath(root, res);
            return res;
        }
};
