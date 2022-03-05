#### Memoization

Memoization is an optimization technique used primarily to speed up computer programs by storing the results 
of expensive function calls and returning the cached result when the same inputs occur again.

Ex:
- Fibonacci number
`
    unordered_map<int,int> hash;
    int fib(int n) {
        if (n<2)
            return n;
        else
            if (hash.find(n)!=hash.end())
                return hash[n];
            else
                return hash[n]=fib(n-1)+fib(n-2);
               
 `
 
 #### Climbing Stairs :
 
You are climbing a staircase. It takes n steps to reach the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

Example 1:

Input: n = 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps
Example 2:

Input: n = 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step


`
int climbStairs(int n)
{
  int dp[n+1];
  dp[n] = 1;
  dp[n-1]=1;
  for(int i = n-2; i >=0 ; i++)
  {
      dp[i] = dp[i+1]+dp[i+2];
  }
  return dp[0];
}
`
TC : O(n) ,SC :  O(n)

`
int climbStairs(int n) {
        int one=1,two=1,temp;
        n--;
        while(n--)
        {
            temp=one;
            one = one+two;
            two = temp;
        }
        return one;
    }
    `
    
TC : O(n) , SC : O(1)
