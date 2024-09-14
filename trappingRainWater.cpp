class Solution 
{
    public:
        int trap(vector<int>& height) 
        {
            int sum = 0, lmax = 0, rmax = 0, l = 0, r = height.size() - 1;

            while (l < r)
            {
                if (height[l] <= height[r])
                {
                    if (height[l] >= lmax)
                    {
                        lmax = height[l];
                    }
                    else 
                    {
                        sum += lmax - height[l];
                    }

                    l += 1;
                }
                else
                {
                    if (height[r] >= rmax)
                    {
                        rmax = height[r];
                    }
                    else
                    {
                        sum += rmax - height[r];
                    }

                    r -= 1;
                }
            }

            return sum;
        }
};
