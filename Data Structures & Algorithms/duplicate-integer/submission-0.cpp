class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        map<int, int>mp;
        for(int i = 0; i < nums.size(); i++)
        {
            mp[nums[i]] += 1;
        }
        for(auto d:mp)
        {
            if(d.second>1)
                return true;
        }
        return false;
    }
};