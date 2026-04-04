class Solution {
public:
    int findDuplicate(vector<int>& nums)
    {
        int low = 1, high = nums.size()-1;
        while(low < high)
        {
            int mid = low + (high-low)/2;
            int cnt = 0;
            for(int i = 0; i < nums.size(); i++)
            {
                if(nums[i] <= mid) cnt++;
            }

            if(cnt <= mid) low = mid+1;
            else high = mid;
        }
        return low;
    }
};
