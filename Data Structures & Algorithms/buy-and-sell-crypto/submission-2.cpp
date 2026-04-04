class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        int minB = prices[0];
        for(int i = 1; i < prices.size(); i++)
        {
            minB = min(minB, prices[i]);
            res = max(res, prices[i]-minB);
        }
        return res;
    }
};
