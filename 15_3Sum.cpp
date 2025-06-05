class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        /* Sort the array */
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        int sum;
        if(nums[nums.size() - 1] < 0)
            return {};
        for(int left = 0; left < (nums.size() - 2); left++){
            /* Avoid duplicated left value*/
            if(left > 0 && nums[left] == nums[left -1])
                continue;
            int middle = left + 1;
            int right = nums.size() - 1;
            /* When smallest value is positive  
               there is no required triplets exists */
            if(nums[left] > 0)
                break;
            while(middle < right){
                sum = nums[left] + nums[middle] + nums[right];
                /* When sum is negative, move middle forward to increase the sum*/
                if(sum < 0)
                    middle++;
                /* When sum is positive, reduce the value of right 
                   Since left and middle start from left, can not be reduced anymore*/
                else if (sum > 0)
                    right--;
                else{
                    result.push_back({nums[left], nums[middle], nums[right]});
                    /* Remove dumplicate nums[middle] and nums[right] */
                    while(middle < right && nums[right - 1] == nums[right])
                        right--;
                    while(middle < right && nums[middle] == nums[middle + 1])
                        middle++;
                    /* Decreas the range of[middle, right]*/
                    middle++;
                    right--;
                }
            }
            

        }
        return result;
    }
};