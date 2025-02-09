#include<vector>

using std::vector;

class Solution {
public:
    /* Function to perform binary serach on a array sorted in ascending order*/
    int search(vector<int>& nums, int target) {
        int left = 0; // Left pointer, start from the beginning of array
        int right = nums.size() - 1; // Right pointer, start from the ending of the array
        int middle; // Variable to stroe the middle index during each iteration
        
        do
        {
            // Calculate middle index
            middle = left + (right - left)/2;

            // Check if the middle element is the target
            if(nums[middle] == target)
                return middle; // Target found
            
            // If the middle element is less than the target, search the right half
            else if (nums[middle] < target)
                left = middle + 1; // Move the left pointer to the right of middle index
            // If the middle element is large than the target, search in the left half
            else
                right = middle - 1; // Move the right pointer to the left of the middle index
        // Continue searching as long as the left pointer is on the left side of the right pointer
        }while(left <= right);
        // If the target is not found, return -1
        return -1;
        
    }
};