class Solution 
{
    void findNge(vector<int> &nge, vector<int>& nums2)
    {
        stack<int> st;

        for (int i = nums2.size() - 1; i >= 0; i--)
        {
            while (!st.empty() && st.top() <= nums2[i])
            {
                st.pop();
            }

            if (st.empty())
            {
                nge[i] = -1;
            }
            else
            {
                nge[i] = st.top();
            }

            st.push(nums2[i]);
        }
    }
    
    public:
        vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) 
        {
            vector<int> nge(nums2.size()), res(nums1.size());

            findNge(nge, nums2);
            
            for (int i = 0; i < nums1.size(); i++)
            {
                auto it = find(nums2.begin(), nums2.end(), nums1[i]);
                int pos = it - nums2.begin();
                res[i] = nge[pos];
            }

            return res;
        }
};
