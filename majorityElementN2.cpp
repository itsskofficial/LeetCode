class Solution 
{
    public:
        int majorityElement(vector<int>& nums) 
        {
            int count = 0, element, temp = 0;

            for (int i = 0; i < nums.size(); i++)
            {
                if (count == 0)
                {
                    element = nums[i];
                    count = 1;
                }
                else if (nums[i] == element)
                {
                    count++;
                }
                else 
                {
                    count--;
                }
            }

            for (int i = 0; i < nums.size(); i++)
            {
                if (nums[i] == element)
                {
                    temp++;
                }
            }

            if (temp > nums.size() / 2)
            {
                return element;
            }

            return -1;
        }
};