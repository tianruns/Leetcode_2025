class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0;
        int sum  = 0;
        int length = nums.size() + 1;
        for(int right = 0; right < nums.size(); right++){
            sum += nums[right];
            while(sum >= target){
                sum -= nums[left];
                length = min(length, right - left + 1);
                left++;
            }                
        }
        return length <= nums.size()? length:0;
    }
};