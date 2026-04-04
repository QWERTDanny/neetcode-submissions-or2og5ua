class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()) return false;
        vector<int> cnt1(26, 0), cnt2(26, 0);

        for(char c : s1)
        {
            cnt1[c-'a']++;
        }

        int l = 0;
        for(int r = 0; r < s2.size(); r++)
        {
            cnt2[s2[r]-'a']++;
            if((r-l+1) > s1.size()) 
            {
                cnt2[s2[l]-'a']--;
                l++;
            }

            if(cnt1 == cnt2) return true;
        }
        return false;
    }
};
