##### Ninja Training
1. A ninja has planned a n-day training schedule. Each day he has to perform one of three activities - running, stealth training, or fighting practice. The same activity cannot be done on two consecutive days and the ninja earns a specific number of merit points, based on the activity and the given day.
   Given a n x 3-sized matrix, where matrix[i][0], matrix[i][1], and matrix[i][2], represent the merit points associated with running, stealth and fighting practice, on the (i+1)th day respectively. Return the maximum possible merit points that the ninja can earn.
   ```
   run = matrix[i][0] + f(i-1,0)
   train = matrix[i][1] + f(i-1,1)
   fight = matrix[i][2] + f(i-1,2)
   return max ( run,train,fight)
   ```

##### Grid unique paths
2. Given two integers m and n, representing the number of rows and columns of a 2d array named matrix. Return the number of unique ways to go from the top-left cell (matrix[0][0]) to the bottom-right cell (matrix[m-1][n-1]).
   Movement is allowed only in two directions from a cell: right and bottom.
   ```
   for top-down> move up, left> return max of them
   for bottom-up > move down, right > return max of them
   ```
##### Unique paths II
3. Given an m x n 2d array named matrix, where each cell is either 0 or 1. Return the number of unique ways to go from the top-left cell (matrix[0][0]) to the bottom-right cell (matrix[m-1][n-1]). A cell is blocked if its value is 1, and no path is possible through that cell.
   Movement is allowed in only two directions from a cell - right and bottom.
   ```
   add extra bases case that
     if(matrix[i][j] == 1 ) return 0;
   ```
##### Minimum path sum in grid
4. Given a 2d array called matrix consisting of integer values. Return the minimum path sum that can be obtained by starting at any cell in the first row and ending at any cell in the last row.
   Movement is allowed only to the bottom, bottom-right, or bottom-left cell of the current cell.
   ```
   start from any value at last row and end at any value in first row.
   if index goes out of bound return infinity.
   get the minimum of all paths i.e: min of  f(i-1,j) , f(i-1,j-1), f(i-1,j+1)
   ```
#####   Min Path in Triangle grid
5. Given a 2d integer array named triangle with n rows. Its first row has 1 element and each succeeding row has one more element in it than the row above it. Return the minimum falling path sum from the first row to the last.
   Movement is allowed only to the bottom or bottom-right cell from the current cell.
   ```
   base case is when j>i we are out of bound return 0;
   start from (0,0), end at any value in last row i.e: (n-1, i) for i->0 to n
   ```
##### Cherry pickup II
6. Given a n x m 2d integer array called matrix where matrix[i][j] represents the number of cherries you can pick up from the (i, j) cell.Given two robots that can collect cherries, one is located at the top-leftmost (0, 0) cell and the other at the top-rightmost (0, m-1) cell.
   Return the maximum number of cherries that can be picked by the two robots in total, following these rules:
    1. Robots that are standing on (i, j) cell can only move to cell (i + 1, j - 1), (i + 1, j), or (i + 1, j + 1), if it exists in the matrix.
    2. A robot will pick up all the cherries in a given cell when it passes through that cell.
    3. If both robots come to the same cell at the same time, only one robot takes the cherries.
    4. Both robots must reach the bottom row in matrix.
```
Both robots always exists in the same row, so mark row with r
Mark robot 1 position with c1 and robot2 position at c2 in ith row
if c1==c2 both robots are at same position pick only once.
else pick both [i][c1] + [i][c2]

while moving down there are 9 possibilities
  (r-1) x (c1-1,c1,c1+1) x (c2-1,c2,c2+1)  1 x 3 x 3 = 9
  
for i: -1 --> 1
  for j: -1 --> 1
       f(r-1,c1+i,c2+j)
```
   
   







   





