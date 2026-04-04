class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, double>> v;
        int count = 0;
        for(int i = 0; i < position.size(); i++)
        {
            double time = (double)(target-position[i]) / speed[i];
            v.push_back({position[i], time});
        }
        sort(v.rbegin(), v.rend());

        double oldT = 0.0;
        for(auto &p : v)
        {
            double curT = p.second;
            if(p.second > oldT)
            {
                count++;
                oldT = curT;
            }
        }
        return count;
    }
};
