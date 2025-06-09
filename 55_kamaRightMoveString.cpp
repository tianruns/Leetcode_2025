#include<iostream>
using namespace std;
int main(){
    int k;
    cin >> k;
    string s;
    char c;
    while(cin >> c)
        s.push_back(c);
    string subS;
    int Len1 = s.size();
    
    if(k <= Len1 / 2){
        subS = s.substr(Len1 - k, k);
        s.erase(Len1 - k, k);
        s = subS + s;
    }
    else{
        subS = s.substr(0, Len1 - k);
        s.erase(0, Len1 - k);
        s = s + subS;
    }
        cout << s;
}