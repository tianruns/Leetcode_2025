#include<iostream>
#include<string>
using std::string;
int main(){
 string s;
 std::cin >> s;
 int n = 0;
 int left = s.size() - 1;
 for(char i:s){
    if (i >= '0' && i <= '9')
        ++n;
 }
 s.resize(s.size() + n * 5);
 int right = s.size() - 1;
 while(right >= 0){
    if (s[left] >= '0' && s[left] <= '9'){
        s[right--] = 'r';
        s[right--] = 'e';
        s[right--] = 'b';
        s[right--] = 'm';
        s[right--] = 'u';
        s[right--] = 'n';
        --left;
    }
    else
        s[right--] = s[left--];
 }

 std::cout << s;

}