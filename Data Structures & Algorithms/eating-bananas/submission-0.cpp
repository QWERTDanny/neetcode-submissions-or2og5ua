class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int R = *max_element(piles.begin(), piles.end());
        int L = 1;
        while(L < R)
        {
            int mid = L+(R-L)/2;
            int time = 0;
            for(int i = 0; i < piles.size(); i++)
            {
                time += (piles[i]+mid-1)/mid;
            }
            if(time <= h) 
            {
                R=mid;
            }
            else 
            {
                L = mid+1;
            }
        }

        return L;
    }
};
