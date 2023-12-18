class Solution 
{
    public:
        int lengthOfLastWord(string s) 
        {
           int i = s.length() - 1;
           int length = 0; 

           while (isspace(s[i]))
           {
               i -= 1;
           }

           while (i >= 0 && !isspace(s[i]))
           {
               length += 1;
               i -= 1;
           }

           return length;
        }
};