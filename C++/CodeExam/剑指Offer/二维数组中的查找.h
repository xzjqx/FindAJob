class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        int m = array.size();
        if(m == 0) return false;
        int n = array[0].size();
        if(n == 0) return false;
        int i = 0, j = n-1;
        while(i < m && j >= 0) {
            if(target < array[i][j]) j --;
            else if(target > array[i][j]) i ++;
            else return true;
        }
        return false;
    }
};