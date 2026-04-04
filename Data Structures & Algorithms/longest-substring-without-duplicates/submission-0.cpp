class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int L = 0, length = 0;
        unordered_set<char> temp;

        for(int R = 0; R < s.length(); R++)
        {
            while(temp.count(s[R]))
            {
                temp.erase(s[L]);
                L++;
            }
            temp.insert(s[R]);
            length = max(length, R-L+1);
        }
        return length;
    }
};
