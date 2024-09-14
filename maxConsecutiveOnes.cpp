class Solution 
{
    public:
        int findMaxConsecutiveOnes(vector<int>& nums) 
        {
            int count = 0, res = 0;
            
            for (int i = 0; i < nums.size(); i++)
            {
                if (nums[i] == 1)
                {
                    count += 1;
                    res = max(count, res);
                }

                else {
                    count = 0;
                }
            }

            return res;
        }
};
