#include<vector>
#include<unordered_set>
using std::vector;
using std::unordered_set;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        /* Count occurence of nums1*/
        unordered_set<int> set1(nums1.begin(), nums1.end());
        unordered_set<int> result;
        for(int i:nums2){
            /* When i of nums2 also exist in set1, it is a intersection element*/
            if(set1.count(i))
                result.emplace(i);
        }
        return vector<int>(result.begin(), result.end());
    }
};