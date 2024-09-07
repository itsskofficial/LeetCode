class Solution 
{
    public:
        vector<int> majorityElement(vector<int>& nums) 
        {
            vector<int> majority;
            int count1 = 0, count2 = 0, element1 = INT_MIN, element2 = INT_MIN;

            for (int i = 0; i < nums.size(); i++)
            {
                if (count1 == 0 && nums[i] != element2)
                {
                    count1 = 1;
                    element1 = nums[i];
                }
                else if (count2 == 0 && nums[i] != element1)
                {
                    count2 = 1;
                    element2 = nums[i];
                }
                else if (nums[i] == element1)
                {
                    count1++;
                }
                else if (nums[i] == element2)
                {
                    count2++;
                }
                else
                {
                    count1--;
                    count2--;
                }
            }

            count1 = count2 = 0;

            for (int i = 0; i < nums.size(); i++)
            {
                if (nums[i] == element1)
                {
                    count1++;
                }
                else if (nums[i] == element2)
                {
                    count2++;
                }
            }

            if (count1 > nums.size() / 3)
            {
                majority.push_back(element1);
            }

            if (count2 > nums.size() / 3)
            {
                majority.push_back(element2);
            }

            return majority;
        }
};
