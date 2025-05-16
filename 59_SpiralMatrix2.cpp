#include<vector>
using std::vector;
class Solution{
public:
    vector<vector<int>> generateMatrix(int n){
        vector<vector<int>> result(n, vector<int>(n));
        int row = 0;
        int col = 0;
        int loop = 0;
        /* Loop the matrix in spiral direction*/
        for(int val = 1; val <= n * n; val++){
            result[row][col] = val;
            /* Move the point from LEFT to RIGHT */
            if(row == loop && col < (n - 1 - loop))
                col++;
            /* Move the point from UP to DOWN*/
            else if(col ==(n - 1- loop) && row < (n - 1 - loop))
                row++;
            /* Move the point from RIGHT to LEFT*/
            else if(row ==(n - 1 - loop) && col > loop)
                col--;
            /* Move the point from DOWN to UP*/
            else if(col == loop && row > (loop + 1))
                row--;
            /* Increase the loop number*/
            else if(col == loop && row == ++loop)
                col++;
        }
        return result;
    }
};