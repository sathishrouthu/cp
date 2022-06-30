### Given a string, find the next smallest palindrome
You are given a number 'N' in the form of a string 'S', your task is to find the smallest number 
strictly greater than the given number 'N' which is a palindrome.
```
Ex:
1221  : 1331
1478  : 1551
9999  : 10001
```

Approach  : 

There are several cases in this problem.

**Given number length is EVEN**

```
when the length of the number is even. we need to check left side digit with right side digit.
ex : if given number is 187342 : then leftside  = 187 and right side = 342
     compare 7 and 3 in this case 7 > 3
     
     CASE 1 -  left side digit > right side digit:
          copy the mirror left half to the right half
     CASE 2 -  left side digit < right side digit:
          increment the leftside digit by 1 and copy mirror left half to right side.
Examples : 
    given number : 2436   : 4>3
                   mirror left half = 42
                   copy mirror left half to right half  : 2442
    
    
```

