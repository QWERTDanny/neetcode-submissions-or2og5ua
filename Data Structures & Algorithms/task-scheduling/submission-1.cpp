class Solution {
public:
    int leastInterval(vector<char>& tasks, int n)
    {
        vector<int> cnt(26, 0);
        for(char task : tasks)
        {
            cnt[task -'A']++;
        }

        int maxf = *max_element(cnt.begin(), cnt.end());

        int maxCnt = 0;
        for(int i : cnt) 
        {
            if(i == maxf) maxCnt++;
        }

        int time = (maxf-1)*(n+1) + maxCnt;
        return max((int)tasks.size(), time);
    }
};
