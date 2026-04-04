class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for(auto s : strs)
        {
            vector<int> temp(26, 0);
            for(auto c : s)
            {
                temp[c-'a']++;
            }
            string key = "";
            for(int i = 0; i < 26; i++)
            {
                key += to_string(temp[i]) + "#";
            }
            mp[key].push_back(s);
        }

        vector<vector<string>> res;
        for(auto &p : mp)
        {
            res.push_back(p.second);
        }
        return res;
    }
};
