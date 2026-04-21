class Solution {
public:
    int maxArea(vector<int>& heights) {
        int area = 0;
        int l = 0, r = heights.size()-1;
        while(l < r) {
            int height = min(heights[l], heights[r]);
            area = max(area, height * (r-l));
            if(heights[r] >= heights[l]) l++;
            else r--;
        }
        return area;
    }
};
