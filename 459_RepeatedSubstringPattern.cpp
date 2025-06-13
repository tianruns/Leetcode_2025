class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int len = s.size();
        vector<int> lps(len, 0);
        int curr = 0;
        for(int i = 1; i < len;){
            if(s[i] == s[curr])
                lps[i++] = ++curr;
            else if(curr == 0)
                ++i;
            else
                curr = lps[curr - 1];
        }
        return lps.back() > 0 && len % (len -lps.back()) == 0;
    }
};