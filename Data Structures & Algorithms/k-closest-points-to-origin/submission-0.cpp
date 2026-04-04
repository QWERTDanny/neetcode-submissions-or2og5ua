class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, pair<int, int>>, 
                        vector<pair<int, pair<int, int>>>, 
                        greater<>> pq;

        for(int i = 0; i < points.size(); i++)
        {
            int distance = points[i][0]*points[i][0] + points[i][1]*points[i][1];
            pq.push({distance, {points[i][0], points[i][1]}});
        }
        vector<vector<int>> res;
        for(int i = 0; i < k; i++)
        {
            auto p = pq.top();
            pq.pop();
            res.push_back({p.second.first, p.second.second});
        }
        return res;
    }
};
