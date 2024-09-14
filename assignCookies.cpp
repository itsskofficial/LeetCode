class Solution 
{
    public:
        int findContentChildren(vector<int>& g, vector<int>& s) 
        {
            int left = 0, right = 0, res = 0;
            sort(g.begin(), g.end());
            sort(s.begin(), s.end());

            while (left < g.size() && right < s.size())
            {
                if (g[left] <= s[right])
                {
                    res++;
                    left++;
                    right++;
                }
                else
                {
                    right++;
                }
            }

            return res;
        }
};
