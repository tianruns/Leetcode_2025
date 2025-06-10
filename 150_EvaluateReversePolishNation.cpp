class Solution {
public:
    void readNum(int& a, int& b, stack<int>& num){
        b = num.top();
        num.pop();
        a = num.top();
        num.pop();
    }
    int evalRPN(vector<string>& tokens) {
        int a, b;
        stack<int> num;
        for(string s:tokens){
            if(s == "+"){
                readNum(a, b, num);
                num.push(a + b);
            }
            else if (s == "-"){
                readNum(a, b, num);
                num.push(a - b);
            }
            else if (s == "*"){
                readNum(a, b, num);
                num.push(a * b);
            }
            else if (s == "/"){
                readNum(a, b, num);
                num.push(a / b);
            }
            else
                num.push(stoi(s));
        }
        return num.top();
    }
};