class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded_string;
        for(auto s : strs)
        {
            encoded_string += to_string(s.size()) + "#" + s;
        }
        return encoded_string;
    }

    vector<string> decode(string s) {
        vector<string> strs;
        int i = 0;
        while(i < s.size())
        {
            int j = i;
            while(s[j] != '#')
            {
                j++;
            }
            int length = stoi(s.substr(i, j-i));
            i = j + 1;
            strs.push_back(s.substr(i, length));
            j = i + length;
            i = j;
        }    
        return strs;
    }
};
