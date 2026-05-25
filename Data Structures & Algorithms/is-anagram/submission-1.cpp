class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;

        unordered_map<char, int> c1;
        unordered_map<char, int> c2;
        for(int i = 0; i < s.length(); i++) {
            c1[s[i]]++;
            c2[t[i]]++;
        }
        return c1 == c2 ;
    }
};
