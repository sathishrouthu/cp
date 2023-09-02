Given an integer n, return an array ans of length n + 1 such that
For each i (0 <= i <= n), ans[i] is the number of 1's in the binary representation of i.

0 <= n <= 10^5

```

Example 1:

Input: n = 2
Output: [0,1,1]
Explanation:
0 --> 0
1 --> 1
2 --> 10

Input: n = 5
Output: [0,1,1,2,1,2]
Explanation:
0 --> 0
1 --> 1
2 --> 10
3 --> 11
4 --> 100
5 --> 101
```
```
if we clearly observe the i and it's binary representations : 

i    binary    set bits
--------------------------
0      0        0 
1      1        1
2      10       1
3      11       2
4      100      1
5      101      2
6      110      2
7      111      3
8      1000     1
```
```
Let if we have X and Y in such a way that,
X/2 = Y
then 
( Number of set bits in X - Number of set bits in Y ) will be either 0 or 1

eg let X = 7and Y = 3
then 7 / 2 = 3;

7 -> 1 1 1 Number of set bit are 3
3 -> 0 1 1 Number of set bit are 2

their difference is 3 - 2 = 1

another eg:
X = 12 and y = 6
then 12 / 2 = 6;

12 -> 1100 number of set bits are 2
6  -> 0110 number of set bits are 2

their difference is 2 - 2 = 0

There can be 2 cases
Whether X is Odd or Even

if X is ODD

- then the (LSB) Least Significant Bit will always be set and dividing by 2 means right shifting the number by 1 bit.
- so if last bit is set and right shift it by 1 bit than the last set bit will be lost.
- therfore the new number Y has 1 set bit less than in compare to X
  
But if X is Even

- then LSB will be equal to 0, 
- Therefore even if we do the right shift by 1 bit, only this 0 bit will be lost and no set bit will get lost
```
```
 
```
```
so When we have X as Even,
no of set bit in X = no of set bit in Y

and When X is ODD
no of set bit in X = 1 + no of set bit in Y

```
CODE

```
class Solution {
public:
    vector<int> countBits(int n) {
        
        // n+1 as we are going to count from 0 to n
        vector<int> ans(n+1);
        
        // t[0] will be 0 because 0 has the count of set bit is 0;
        ans[0] = 0;
        
        //We can compute the current set bit count using the previous count
        // as x/2 in O(1) time
        
        // i%2 will be 0 for even numbers and 1 for odd numbers
        
        for(int i = 1; i<=n; ++i)
            ans[i] = ans[i/2] + i%2;
        
        return ans;
    }
};

```


 
