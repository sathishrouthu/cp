```
Find the validity of an input string s that only contains the letters '(', ')' and '*'.
A string entered is legitimate if

Any left parenthesis '(' must have a corresponding right parenthesis ')'.
Any right parenthesis ')' must have a corresponding left parenthesis '('.
Left parenthesis '(' must go before the corresponding right parenthesis ')'.
'*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string "".
Input : s = "(*))"
Output : true
Input : s = "*(()"
Output : false
```
**Bruteforce:**

check all possibilities of asterick using recusrion,
can be optimized using dp.

```
 private boolean checkValid(int ind, int count, String s, int[][] dp) {
        // Base case 
        if (count < 0) return false;
        // Base case
        if (ind == s.length()) {
            return (count == 0);
        }

        // If already computed, return the value directly
        if (dp[ind][count] != -1) return dp[ind][count] == 1;

        boolean ans = false;

        // If the current index has '('
        if (s.charAt(ind) == '(')
            ans = checkValid(ind + 1, count + 1, s, dp);
        // If the current index has ')'
        else if (s.charAt(ind) == ')')
            ans = checkValid(ind + 1, count - 1, s, dp);
        
        // else if the current index has '*'
        else {
            for (int i = -1; i <= 1; i++) {
                ans = ans || checkValid(ind + 1, count + i, s, dp);
            }
        }

        // Store the value in DP and return the value
        dp[ind][count] = ans ? 1 : 0;
        return ans;
    }

```
**Optimal:**
```
in prevoius approach we are using count to check balance b/w open and closed parnthesis.
now, to handle astericks we can maintain two variables which represents possible values of count of open paranthesis.
minOpen: represents minimum possible no. of open paranthesis remain at end.
maxOpen: represents maximum possible no. of open paranthesis remain at end.

if we encounter a '(' : both minOpen and maxOpen are incremented,
if we encounter a ')' : both minOpen and maxOpen are decremented (since it will close a open paranthesis )
if we encounter a '*' : minOpen should be decremented ( assuming '*' as a ')' )
                        maxOpen should be incremented ( assuming '*' as a '(' )
at any case:
if maxOpen < 0 then it means that a closing appeared without any opening before which is invalid. ( return false )
if minOpen < 0 then we assumed a closing without it's opening, we should not use ')' for * when there is no '(' before.
               ( reset minOpen to 0 ) minOpen should be decreased only if it is greater than 0.
At the end:
minOpen should be 0, if the string is a valid.
otherwise it is not valid and leaves some open paranthesis
```
```
  public boolean isValid(String s) {
      int minOpen=0,maxOpen=0;
      for(char c:s.toCharArray()){
          if(c=='('){
              minOpen++;
              maxOpen++;
          }else if(c==')'){
              maxOpen--;
              minOpen--;
          }else{
              minOpen--;
              maxOpen++;
          }
          if(maxOpen < 0) return false;
          if(minOpen < 0) minOpen = 0;
      }
      return minOpen==0;
  }
```
