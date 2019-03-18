class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
        vector<int> ans;
        int m = matrix.size();
        if(m == 0) return ans;
        int n = matrix[0].size();
        if(n == 0) return ans;
        if(m == 1 && n == 1) {
            ans.push_back(matrix[0][0]);
            return ans;
        }
        int i = 0, j = 0, m0 = 0, n0 = 0, m1 = m-1, n1 = n-1;
        int index = 0;
        while(m1 > m0 && n1 > n0) {
            if(i == m0 && j < n1) {
                while(j < n1) {
                    ans.push_back(matrix[i][j++]);
                    index ++;
                }
            } else if(j == n1 && i < m1) {
                while(i < m1) {
                    ans.push_back(matrix[i++][j]);
                    index ++;
                }
            } else if(i == m1 && j > n0) {
                while(j > n0) {
                    ans.push_back(matrix[i][j--]);
                    index ++;
                }
            } else if(j == n0 && i > m0) {
                while(i > m0) {
                    ans.push_back(matrix[i--][j]);
                    index ++;
                }
                i ++;
                j ++;
                m0 ++;
                n1 --;
                m1 --;
                n0 ++;
            }
        }
        if(index < m * n) {
            if(n1 >= m1) {
                while(j <= n1)
                    ans.push_back(matrix[m1][j++]);
            } else {
                while(i <= m1)
                    ans.push_back(matrix[i++][n1]);
            }
        }
        return ans;
    }
};