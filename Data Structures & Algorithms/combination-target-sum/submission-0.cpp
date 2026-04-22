class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        vector<int> subset;
        int sum = 0;
        dfs(nums, 0, target, subset, res);
        return res;
    }

    void dfs(vector<int>& nums, int i, int target, 
             vector<int>&subset, 
             vector<vector<int>>& res) {
        if(target == 0) {
            res.push_back(subset);
            return;
        }

        if(i >= nums.size() || target < 0) return;

        subset.push_back(nums[i]);
        dfs(nums, i, target - nums[i], subset, res);
        subset.pop_back();
        dfs(nums, i+1, target, subset, res);
    }
};
