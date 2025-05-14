class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int left  = 0;
        int right = nums.size() - 1;
        vector<int>result(nums.size());
        for(int i = result.size() - 1; i > -1; i--){
            if(nums[left] * nums[left] > nums[right] * nums[right]){
                result[i] = nums[left] * nums[left];
                left++;
            }
            else{
                result[i] = nums[right] * nums[right];
                right--;
            }
        }
        return result;
    }
};