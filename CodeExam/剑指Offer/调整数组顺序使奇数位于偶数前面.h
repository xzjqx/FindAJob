class Solution {
public:
    void reOrderArray(vector<int> &array) {
        int len = array.size();
        if(len == 0) return;
        for(int i = 1; i < len; i ++) {
            if(array[i] % 2 == 1) {
                int j = i;
                int tmp = array[i];
                while(j > 0 && (array[j-1] % 2 == 0)){
                    array[j] = array[j-1];
                    j --;
                }
                array[j] = tmp;
            }
        }
    }
};