#include<vector>
using std::vector;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        /*If current sum is positive, we shall continue to sum 
        Because the next val + current sum(positive) > next value  --> no need to change start point*/

        /*If current sum is negative, we shall change start point
        Because the next value > next value + current sum(negative) --> new start larger than continue sum*/

        int currSum = 0;
        int result = INT_MIN;

        for(int i = 0; i < nums.size(); i++){
            currSum += nums[i];
            if(currSum > result)
                result = currSum;
            if(currSum < 0)
                currSum = 0;
        }

        return result;
    }
};