class Solution 
{
    public:
        int mySqrt(int x) 
        {
            int left = 0;
            int right = x;
            int result = 0;
            int mid = 0;

            while (left <= right)
            {
                mid = left + ((right - left) / 2);
                if (pow(mid, 2) > x)
                {
                    right = mid - 1;
                }
                
                else if (pow(mid, 2) < x)
                {
                    left = mid + 1;
                    result = mid;
                }
                
                else
                {
                    return mid;
                }               
            }

            return result;
        }
};
