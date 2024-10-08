class Solution 
{
    public:
        int widthOfBinaryTree(TreeNode* root) 
        {
            if (!root)
            {
                return 0;
            }

            int res = 0;
            queue<pair<TreeNode*, long long>> q;  // Use 'long long' for IDs
            q.push({root, 0});

            while (!q.empty())
            {
                int size = q.size();
                long long min = q.front().second;  
                long long first, last;

                for (int i = 0; i < size; i++)
                {
                    long long currIndex = q.front().second - min;  
                    TreeNode* node = q.front().first;
                    q.pop();

                    if (i == 0)
                    {
                        first = currIndex;
                    }

                    if (i == size - 1)
                    {
                        last = currIndex;
                    }

                    if (node->left)
                    {
                        q.push({node->left, currIndex * 2 + 1});
                    }

                    if (node->right)
                    {
                        q.push({node->right, currIndex * 2 + 2});
                    }
                }

                res = max(res, (int)(last - first + 1)); 
            }

            return res;
        }
};
