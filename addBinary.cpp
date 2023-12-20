class Solution 
{
    public:
        string addBinary(string a, string b) 
        {
            string result = "";
            string x;
            int carry = 0;
            int digitA;
            int digitB;
            int total;
            
            reverse(a.begin(), a.end());
            reverse(b.begin(), b.end());

            for (int i = 0; i < max(a.length(), b.length()); i++)
            {
                if (i < a.length())
                {
                    digitA = stoi(string(1, a[i]));
                }

                else
                {
                    digitA = 0;
                }

                if (i < b.length())
                {
                    digitB = stoi(string(1, b[i]));
                }

                else
                {
                    digitB = 0;
                }

                total = digitA + digitB + carry;
                x = to_string(total % 2);
                result = x + result;
                carry = total / 2;
            }

            if (carry == 1)
            {
                result = "1" + result;
            }

            return result;
        }
};