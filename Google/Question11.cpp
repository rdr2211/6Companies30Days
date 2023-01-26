/*
Company :- Google
11. Matrix Block Sum

Given a m x n matrix mat and an integer k, return a matrix answer where each answer[i][j] is the sum of all elements mat[r][c] for:

i - k <= r <= i + k,
j - k <= c <= j + k, and
(r, c) is a valid position in the matrix.
 

Example 1:

Input: mat = [[1,2,3],[4,5,6],[7,8,9]], k = 1
Output: [[12,21,16],[27,45,33],[24,39,28]]
Example 2:

Input: mat = [[1,2,3],[4,5,6],[7,8,9]], k = 2
Output: [[45,45,45],[45,45,45],[45,45,45]]
 

Constraints:

m == mat.length
n == mat[i].length
1 <= m, n, k <= 100
1 <= mat[i][j] <= 100
*/
class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        // Intuition cumulative sum
        int row = mat.size();
        int col = mat[0].size();

        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                int a = 0, b = 0;
                if(i != 0) a += mat[i - 1][j];
                if(j != 0) b += mat[i][j - 1];

                mat[i][j] += a + b;
                if(i != 0 && j != 0) mat[i][j] -= mat[i - 1][j - 1];
            }
        }

        vector<vector<int>> ans(row, vector<int>(col));
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                int r =  i + k, c =  j + k;
                if(i + k >= row - 1) r = row - 1;
                if(j + k >= col - 1) c = col - 1;

                ans[i][j] = mat[r][c];

                int tr = i - k, tc = j - k;
                if(i - k > 0) ans[i][j] -= mat[i - k - 1][c];
                if(j - k > 0) ans[i][j] -= mat[r][j - k - 1];
                if(i - k > 0 && j - k > 0) ans[i][j] += mat[i - k - 1][j - k - 1];
            }
        }

        return ans;
    }
};
