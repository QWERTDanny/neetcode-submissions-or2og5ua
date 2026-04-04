class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> mp;

    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].emplace_back(timestamp, value);
    }
    
    string get(string key, int timestamp) {
        auto& values  = mp[key];
        int L = 0, R = values.size()-1;
        string result = "";

        while( L <= R)
        {
            int mid = L+(R-L)/2;
            if(values[mid].first <= timestamp)
            {
                result = values[mid].second;
                L = mid+1;
            }else
            {
                R = mid-1;
            }
        }
        return result;
    }
};
