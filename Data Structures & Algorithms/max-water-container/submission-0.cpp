class Solution {
public:
    int maxArea(vector<int>& heights) {
        int area = 0;
        int L = 0; int R = heights.size()-1;
        while(L < R)
        {
            int height = min(heights[L], heights[R]);
            area = max(area, height*(R-L));
            if(heights[R] >= heights[L])
                L++;
            else
                R--;
        }
        return area;
    }
};
