#include<unordered_set>
using::std::unordered_set;

class Solution {
public:
    int digitSqare(int n){
        /* Calculate the square of each digit*/
        int sum = 0;
        while(n){
            sum += (n % 10) * (n % 10);
            n = n/10;
        }
        return sum;
    }
    bool isHappy(int n) {
        unordered_set<int> circle;
        while(n != 1){
            n = digitSqare(n);
            /* When n is already in the circle set, we are in the loop.*/
            if(circle.count(n))
                return false;
            else
                circle.insert(n);
        }
        return true;
    }
};