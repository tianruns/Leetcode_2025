class Solution {
public:
    /* From start, find the sum of two equals to target */
    vector<vector<int>> twoSum(vector<int>::iterator begin, vector<int>::iterator end, long long target){
        --end;
        vector<vector<int>> result;
        while(begin < end){
            int sum = *begin + *end;
            if(sum < target)
                ++begin;
            else if (sum > target)
                --end;
            else{
                /* Add qualified pairs*/
                result.push_back({*begin, *end});
                ++begin;
                --end;
                /*Avoid duplicate pairs*/
                while(begin < end && *begin == *(begin - 1)) ++begin;
                while(begin < end && *end == *(end + 1)) --end;
            }
        }
        return result;
    }
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if(nums.size() < 4)
            return {};
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        for(int i = 0; i < nums.size() - 3; ++i){
            /* Remove duplicate value */
            if(i > 0 && nums[i - 1] == nums[i])
                continue;
            for(int j = i + 1; j < nums.size() - 2; ++j){
                if(j > i + 1 && nums[j] == nums[j - 1])
                    continue;
                long long currTarget = (long long)target - nums[i] - nums[j];
                vector<vector<int>> pairs = twoSum(nums.begin() + j + 1, nums.end(), currTarget);
                for(const vector<int>& pair:pairs){
                    result.push_back({nums[i], nums[j], pair[0], pair[1]});
                }
            }
        }
        return result;

    }
};