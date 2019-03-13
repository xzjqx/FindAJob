class Solution {
public:
    int jumpFloorII(int number) {
        if(number <= 0) return 1;
        if(number == 1) return 1;
        int sum = 2, a;
        for(int i = 2; i <= number; i ++) {
            a = sum;
            sum += a;
        }
        return a;
    }
    int jumpFloorIII(int number) {
        if(number <= 0) return 0;
        if(number == 1) return 1;
        return 2*jumpFloorIII(number-1);
    }
};