class Solution {
public:
    void reverseS(string &s, int left, int right){
        char temp;
        /* Swap left, right pointer
           Move left forward and right backward*/ 
        while(left < right){
            temp = s[right];
            s[right--] = s[left];
            s[left++] = temp;
        }
    }

    void removeExtraSpace(string& s){
        /* Fast find non-space char*/
        /* Curr rewrite words and add spaces*/
        int curr = 0;
        for(int fast = 0; fast < s.size(); ++fast){
            /*Skip spaces*/
            if(s[fast] == ' ') continue;
            /*Fast finds spaces 
              1. End of a word
              2. Spaces at the beginning*/
            /* Curr not at begin -> curr has rewritten the word and reach the end of a word, need to add space*/
            if(curr != 0) s[curr++] = ' ';
            while(fast < s.size() && s[fast] != ' ')
                s[curr++] = s[fast++];
        }
        s.resize(curr);
    }
    string reverseWords(string s) {
        removeExtraSpace(s);
        reverseS(s, 0, s.size() - 1);
        /* Reverse sigle word*/
        for(int left = 0; left < s.size();){
            int right = left;
            while(right < s.size() && s[right] != ' ') ++right;
            reverseS(s, left, right - 1);
            left = right + 1;
        }
        return s;
    }
};