class Solution 
{
    void findSubsets(int index, vector<int> &nums, vector<int> &temp, vector<vector<int>> &res)
    {
        res.push_back(temp);
        for (int i = index; i < nums.size(); i++)
        {
            if (i != index && nums[i] == nums[i-1])
                continue;

            temp.push_back(nums[i]);
            findSubsets(i+1, nums, temp, res);
            temp.pop_back();
        }
    }
    public:
        vector<vector<int>> subsetsWithDup(vector<int>& nums) 
        {
            vector<vector<int>> res;
            vector<int> temp;
            sort(nums.begin(), nums.end());
            findSubsets(0, nums, temp, res);
            return res;
        }
};
