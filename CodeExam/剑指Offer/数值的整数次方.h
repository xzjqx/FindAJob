class Solution {
public:
    double Power(double base, int exponent) {
        double ans = 1;
        for(int i = 0; i < abs(exponent); i ++) {
            ans *= base;;
        }
        if(exponent < 0) ans = 1/ans;
        return ans;
    }
};