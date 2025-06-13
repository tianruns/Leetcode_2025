class Solution {
public:
    vector<int> getLps(const string& needle){
        
        if(needle.size() == 0)
            return {};
        /* First index has 0 prefix and suffix*/
        vector<int> result(needle.size(), 0);
        int currLen = 0;
        for(int i = 1; i < needle.size();){
            /* Last suffix(current) element equals to next element(len) after last prefix element(len - 1)
               Increase the lenth of LPS (longest prefix suffix) Save it */
            if(needle[i] == needle[currLen])
                result[i++] = ++currLen;
            /* Current longest length is 0 -> no possible commone LSP, Save it*/
            else if(currLen == 0)
                ++i;
            /* Mismatch and currLen > 0 
               Current longest mismatch, but we can start from second longest LPS
               A precondition of current LPS: current suffix == current prefix
               Second LPS: suffix of current suffix == prefix of current prefix
               -> suffix of current prefix == prefix of current prefix -> the longest length at end of current prefix (len - 1)*/
            else
                currLen = result[currLen - 1];
        }
        return result;
    }
    int strStr(string haystack, string needle) {
        if(haystack.empty() || needle.empty())
            return -1;
        vector<int> lps = getLps(needle);
        int needleIndex = 0;
        for(int i = 0; i < haystack.size();){
            /*Match, move needle forward*/
            if(haystack[i] == needle[needleIndex]){
                ++needleIndex;
                ++i;
            }
            else if(needleIndex == 0)
                ++i;
            /*Mismatch, move needle to LPS position*/
            else {
                needleIndex = lps[needleIndex - 1];
            }
            if(needleIndex ==  needle.size())
                return i - needleIndex;
        }
        return -1;
    }
};