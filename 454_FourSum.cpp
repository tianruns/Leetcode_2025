class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int> mapAB;
        int count = 0;
        /* Accumulate nums1 and nums2 element, put it into map*/
        for(int i:nums1){
            for(int j:nums2)
                mapAB[i + j]++;
        }
        /* Accumulate nums3 and nums4*/
        for(int i:nums3){
            for(int j:nums4){
                /* Add count if corelated element exist*/
                if(mapAB.count(-i - j))
                    count+=mapAB[-i-j];
            }
        }
        return count;
    }
};