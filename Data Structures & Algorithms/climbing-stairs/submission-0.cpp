class Solution {
public:
    int climbStairs(int n) {
        vector<int> res(n+1, -1);
        return dfs(n, res);
    }

    int dfs(int n, vector<int> &res) {
        if(n <= 2) return n;
        if(res[n] != -1) return res[n];
        res[n] = dfs(n-1, res) + dfs(n-2, res);
        return res[n];
    }
};
