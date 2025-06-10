class Solution {
public:
    string removeDuplicates(string s) {
        string result;
        for(char i:s){
            /* Add new char*/
            if(result.empty() || result.back() != i)
                result.push_back(i);
            /* Remove adjacent duplicates*/
            else
                result.pop_back();
        }
        return result;
    }
};