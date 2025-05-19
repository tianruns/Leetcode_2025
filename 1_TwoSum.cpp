#include<unordered_map>
using std::unordered_map;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> set;
        for(int i = 0; i < nums.size(); i++){
            /* Find another matched element exist in map*/
            if(set.count(target - nums[i]))
                return {set[target - nums[i]], i};
            /* Add nums[i] to map, key = value, val = index*/
            else
                set[nums[i]] = i;
        }
        return vector<int>{};
    }
};