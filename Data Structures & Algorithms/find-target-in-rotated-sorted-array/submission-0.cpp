class Solution {
public:
    int search(vector<int>& nums, int target) {
        int L = 0, R = nums.size()-1;
        while(L < R)
        {
            int mid = L + (R-L) / 2;
            if(nums[mid] > nums[R]) L = mid+1;
            else R = mid;
        }
        int min = L;
        L = 0; R = nums.size()-1;
        if(target >= nums[min] && target <= nums[R])
        {
            L = min;
        }
        else
        {
            R = min-1;
        }
        
        while(L <= R)
        {
            int mid = L + (R-L)/2;
            if(nums[mid] > target) R = mid-1;
            else if(nums[mid] < target) L = mid+1;
            else return mid;
        }
        return -1;
    }
};
