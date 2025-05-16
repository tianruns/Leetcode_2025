class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0;
        int sum  = 0;
        int length = nums.size() + 1;
        for(int right = 0; right < nums.size(); right++){
            sum += nums[right];
            while(sum - nums[left] >= target){
                sum -= nums[left];
                left++;
                length = min(length, right - left + 1);
            }
            if(sum >= target)
                
        }
        return length == (nums.size()+1)? 0:length;
    }
};