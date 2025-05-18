#include <string>
using std::string;
class Solution {
public:
    bool isAnagram(string s, string t) {
        int word[26] = {};
        /* Count the occurence number of each character*/
        for(auto i:s)
            word[i - 'a']++;
        for(auto i:t)
            word[i - 'a']--;
        for(auto i:word){
            if (i)
                return false;
        }
        return true;
    }
};