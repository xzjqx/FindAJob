class Solution {
public:
    int NumberOf1(int n) {
        int sum = 0;
        for(int i = 0; i < 31; i ++) {
            sum += n&1;
            n = n >> 1;
        }
        if(n < 0) sum ++;
        return sum;
    }
    int NumberOf1I(int n) {
        int count = 0;
        while(n != 0) {
            count ++;
            n &= (n - 1);
        }
        return count;
    }
};