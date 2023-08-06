string convert(string s, int numRows) {
        if(numRows==1) return s;
        int stringLength = s.size();
        int numSections = ceil(stringLength / (2*numRows - 2.0));
        int numCols = numSections*2;
        vector<vector<char>> mat(numRows,vector<char>(numCols,' ' ));
        int stringIndex = 0;
        int rowIndex = 0;
        int colIndex = 0;
        while(stringIndex < stringLength){
            while(rowIndex<numRows && stringIndex < stringLength){
                mat[rowIndex][colIndex] = s[stringIndex];
                rowIndex++;
                stringIndex++;
            }
            rowIndex-=2;
            colIndex++;

            while(rowIndex>0 && colIndex < numCols && stringIndex<stringLength){
                mat[rowIndex][colIndex] = s[stringIndex];
                rowIndex--;
                stringIndex++;
            }
            colIndex++;
        }
        string ans = "";
        for(int i=0;i< numRows;i++){
            for(int j=0;j<numCols;j++){
                if(mat[i][j]!=' ')
                    ans += mat[i][j];
            }
        }
        return ans;
}