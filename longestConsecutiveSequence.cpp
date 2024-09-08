class Solution 
{
    public:
        int longestConsecutive(vector<int>& nums) 
        {
            if (nums.size() == 0)
            {
                return 0;
            }

            int longest = 1;
            unordered_set<int> seq;

            for (int i = 0; i < nums.size(); i++)
            {
                seq.insert(nums[i]);
            }

            for (auto it : seq)
            {
                if (seq.find(it - 1) == seq.end())
                {
                    int count = 1;
                    int x = it;

                    while (seq.find(x + 1) != seq.end())
                    {
                        count++;
                        x++;
                    }

                    longest = max(longest, count);
                }
            }
            
            return longest;
        }
};
