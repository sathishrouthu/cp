/*
Given a matrix, your task is to rotate the matrix 90 degrees clockwise.


Sol : 
Transpose the matrix;
reverse each row of the matrix; 

for 90 degree anti clock wise:

reverse each column instead of row after transpose;

*/


void rotate(vector<vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    for(int i=0;i<m;i++){
        for(int j=0;j<i;j++){
            swap(matrix[i][j],matrix[j][i]);
        }
    }
    for(int i=0;i<m;i++){
        reverse(matrix[i].begin(),matrix[i].end());
    }
}
