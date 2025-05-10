#include<vector>
#include<algorithm>
using std::vector;
using std::sort;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int numOfContent = 0;
        int cookieIndex = s.size() - 1;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        
        for(int i = g.size() - 1; i > -1; i--){
            if(cookieIndex > -1 && s[cookieIndex] >= g[i]){
                cookieIndex--;
                numOfContent++;
            }
        }
        return numOfContent;


    }

    int findContentChildren_2(vector<int>& g, vector<int>& s) {
        /*sort the greedy and cookies*/
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int ContentChildren = 0;
        int notContentChild = 0;
        for(int i = 0; i < s.size(); i++){
            /*Try to give the smallest cookie to least gready child*/
            if(notContentChild < g.size() && s[i] >= g[notContentChild]){
                ContentChildren++;
                notContentChild++;
            }
            /*Otherwise, try next bigger cookie*/
        }
        return ContentChildren;
    }
};