//T.C : O((m x n) + (m x n)).
//S.C : O(m) + O(n).
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int row[m];
        memset(row,-1,sizeof(row));
        int col[n];
        memset(col,-1,sizeof(col));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j] == 0){
                    row[i] = 0;
                    col[j] = 0;
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(row[i] == 0 || col[j] == 0){
                    matrix[i][j] = 0;
                }
            }
        }
    }
};
