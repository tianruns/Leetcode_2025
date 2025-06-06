class Solution {
public:
    void reverseK(string&s, int left, int right){
        while(left < right){
            swap(s[left], s[right]);
            ++left;
            --right;
        }
    }
    string reverseStr(string s, int k) {
        int left = 0;
        int right = k - 1;
        while(left < s.size() - 1){
            /* There are K or more than K chars left*/
            if(right < s.size())
                reverseK(s, left, right);
            /* There are fewer than K chars left*/
            else
                reverseK(s, left, s.size() -  1);
            left += 2 * k;
            right += 2 * k;
        }
        return s;
    }
};