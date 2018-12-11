class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        int maxlen = 0;
        int len = s.length();
        int start = 0;
        int sublen = 1;
        while(start <= len && (start + sublen) <= len + 1)
        {   
            string substring = s.substr(start, sublen);
            char new_char = substring[substring.length()-1];
            if(is_non_repeated_string(substring, new_char))
            {
                update(substring, maxlen);
                sublen++;
            }
            else
            {
                start++;
                sublen = 1;
            }
        }
        return maxlen;
    }
    bool is_non_repeated_string(string s, char c)
    {
        if(s.length() == 1)
            return 1;
        else
        {
            for(int i = 0; i < (s.length() - 1); i++)
            {
                if (s[i] == c)
                    return 0;
            }
        return 1;
        }
    }
    void update(string s, int& maxlen)
    {   
        if(s.length() > maxlen)
        {
            maxlen = s.length();
        }
    }
};
