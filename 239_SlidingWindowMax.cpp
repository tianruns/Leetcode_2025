
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> numQue;
        vector<int> result;
        for(int i = 0; i < nums.size(); ++i){
            /* If the end of queue <= nums[i], remove it*/
            while(numQue.size() != 0 && nums[i] > numQue.back())
                numQue.pop_back();
            /* Add new element in the end of Queue*/
            numQue.push_back(nums[i]);
            
            if(i > (k - 1) && nums[i - k] == numQue.front())
                numQue.pop_front();
            /* Window has full, add the first element to the result vector*/
            if(i >= (k - 1))
                result.push_back(numQue.front());
        }
        return result;
    }
};