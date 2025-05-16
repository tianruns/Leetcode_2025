#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n, a, b;
    cin >> n;
    vector<int> num(n);
    vector<int> subSum(n);
    int preSum = 0;
    for(int i = 0; i < n; i++){
        cin >> num[i];
        preSum += num[i];
        subSum[i] = preSum;
    }
    while(cin >> a >> b){
        if(a == 0)
            cout << subSum[b] << "\n";
        else
            cout << subSum[b] - subSum[a - 1] << "\n";
    }
}