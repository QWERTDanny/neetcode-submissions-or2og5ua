class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int L = 0, R = 1;
        int res = 0;

        while(R < prices.size())
        {
            if(prices[R] <= prices[L])
            {
                L = R;
            }
            else
            {
                int p = prices[R] - prices[L];
                res = max(res, p);
            }
            R++;
        }
        return res;
    }
};
