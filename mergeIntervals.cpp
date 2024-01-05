class Solution 
{
    public:
    
        bool compareIntervals(const vector<int>& i1, const vector<int>& i2) 
        { 
            return (i1[0] < i2[0]); 
        }

        vector<vector<int>> merge(vector<vector<int>>& intervals) 
        {
            sort(intervals.begin(), intervals.end(), [this](const auto& i1, const auto& i2) 
            {
                return compareIntervals(i1, i2);
            });

            vector<vector<int>> result = {intervals[0]};

            for (int i = 1; i < intervals.size(); i++)
            {
                if (intervals[i][0] <= result[result.size() - 1][1])
                {
                    result[result.size() - 1][1] = max(result[result.size() - 1][1], intervals[i][1]);
                }

                else
                {
                    result.push_back({intervals[i][0], intervals[i][1]});
                }
            }

            return result;
        }
};