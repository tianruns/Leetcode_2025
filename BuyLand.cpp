#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n, m;
    cin >> n >> m;
    vector<int>rowSum(n);
    vector<int>colSum(m);
    int sum = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            int val;
            cin >> val;
            rowSum[i] += val;
            colSum[j] += val;
            sum += val;
        }
    }

    int minDiff = sum;
    int aVal = 0;
    for(int i = 0; i < n; i++){
        aVal += rowSum[i];
        if(abs(sum - aVal -aVal) < minDiff)
            minDiff = abs(sum - aVal -aVal);
    }
    aVal = 0;
    for(int i = 0; i < m; i++){
        aVal += colSum[i];
        if(abs(sum - aVal -aVal) < minDiff)
            minDiff = abs(sum - aVal -aVal);
    }

    cout << minDiff;


}