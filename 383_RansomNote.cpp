#include<unordered_map>
#include<string>
using std::string;
using std::unordered_map;
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> magaSet;
        for(char i:magazine)
            magaSet[i]++;
        for(char i:ransomNote){
            auto x = magaSet.find(i);
            if(x!= magaSet.end() && x -> second)
                magaSet[i]--;
            else
                return false;
        }
        return true;
    }
};