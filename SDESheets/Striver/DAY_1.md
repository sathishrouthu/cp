### Set Matrix Zero
**Problem Statement:**  Given a matrix if an element in the matrix is 0 then you will have to set its entire column and row to 0 and then return the matrix.

```
vector<vector<int>> findGoodMatrix(vector<vector<int>> &arr) 
{
    int r = arr.size();
    int c = arr[0].size();
    int col0=0;
    for(int i=0;i<r;i++){
        if(arr[i][0]==0)
            col0=1;
        for(int j=1;j<c;j++){
            if(arr[i][j]==0){
                arr[i][0]=0;
                arr[0][j]=0;
            }
        }
    }
    for(int i=r-1;i>=0;i--){
        for(int j=c-1;j>0;j--){
            if(arr[i][0]==0 || arr[0][j]==0){
                arr[i][j]=0;
            }
        }
        if(col0==1){
           arr[i][0]=0;
        }
    }
    return arr;
}

```

### Pascal’s Triangle

 Given an integer N, return the first N rows of Pascal’s triangle.

In Pascal’s triangle, each number is the sum of the two numbers directly above it as shown in the figure below

```
Input Format: N = 5

Result:
    1
   1 1
  1 2 1
 1 3 3 1
1 4 6 4 1

Explanation: There are 5 rows in the output matrix. Each row corresponds to each one of the rows in the image shown above.

```

