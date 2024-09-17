class Solution 
{
    public:
        double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
        {
            int i = 0, j = 0, count = 0, index1 = -1, index2 = -1;
            int element1 = 0, element2 = 0, n = nums1.size() + nums2.size();
            
            index1 = (n - 1) / 2;
            index2 = n / 2;

            while (i < nums1.size() && j < nums2.size()) 
            {
                if (nums1[i] < nums2[j]) 
                {
                    if (count == index1) element1 = nums1[i];
                    if (count == index2) element2 = nums1[i];
                    i++;
                } 
                else 
                {
                    if (count == index1) element1 = nums2[j];
                    if (count == index2) element2 = nums2[j];
                    j++;
                }
                count++;
            }

            while (i < nums1.size()) 
            {
                if (count == index1) element1 = nums1[i];
                if (count == index2) element2 = nums1[i];
                i++;
                count++;
            }

            while (j < nums2.size()) 
            {
                if (count == index1) element1 = nums2[j];
                if (count == index2) element2 = nums2[j];
                j++;
                count++;
            }

            if (n % 2 == 0) 
            {
                return (element1 + element2) / 2.0;
            }

            return element2;
        }
};
