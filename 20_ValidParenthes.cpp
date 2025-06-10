class Solution {
public:
    bool isValid(string s) {
        stack<char> bracket;
        for(char i:s){
            if(i == '(')
                bracket.push(')');
            else if (i == '[')
                bracket.push(']');
            else if (i == '{')
                bracket.push('}');
            else if(bracket.empty() || bracket.top() != i)    
                return false;
            else
                bracket.pop();
        }
        return bracket.empty();
    }
};