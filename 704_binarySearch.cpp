#include<vector>

using std::vector;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int middle;
        
        do
        {
            middle = (left + right) / 2;

            if(nums[middle] == target)
                return middle;
            else if (nums[middle] < target)
                left = middle + 1;
            else
                right = middle - 1;

        }while(left <= right);

        return -1;
        
    }
};