class Solution {
public:
    int trap(vector<int>& height) {
        int L = 0, R = height.size()-1;
        int leftMax = height[L], rightMax = height[R];
        int res = 0;

        while(L < R)
        {
            if(leftMax < rightMax)
            {
                L++;
                leftMax = max(leftMax, height[L]);
                res += leftMax - height[L];
            }else
            {
                R--;
                rightMax = max(rightMax, height[R]);
                res += rightMax - height[R];
            }
        }
        return res;
    }
};
