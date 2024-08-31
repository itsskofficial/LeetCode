class Solution 
{
    public:
        void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) 
        {
           int p1, p2;
           p1 = m - n - 1;
           p2 = 0;

           while (p1 >= 0 && p2 < n)
           {
            if (nums1[p1] > nums2[p2])
            {
                swap(nums1[p1], nums2[p2]);
                p1--;
                p2++;
            }
            else 
            {
                break;
            }
           }

           sort(nums2.begin(), nums2.end());    
           
           for (int i = m, j = 0; i < m + n; i++, j++)
           {
            nums1[i] = nums2[j];
           }

           sort(nums1.begin(), nums1.end());
        }
};