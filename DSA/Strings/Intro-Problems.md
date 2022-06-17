### Encode the Message (Run length encoding)

You have been given a text message. You have to return the Run-length Encoding of the given message.
For example, the string "aaaabbbccdaa" would be encoded as "a4b3c2d1a2".

```
string encode(string &s)
{
   int c=1;
   string ans;
   for(int i=0;i<s.size();i++)
   {  
       if(s[i]==s[i+1])
           c++;
       else{
           ans+=s[i]+to_string(c);
           c=1;
       }
   }
   return ans;
}

```

### Remove Vowels from a string

ex : 

ip :  sathish

op :  sthsh

```
#include<bits/stdc++.h>
string removeVowels(string s) {
    vector<char>  vow = {'a', 'e', 'i', 'o', 'u','A', 'E', 'I', 'O', 'U'};
    for(int i=0;i<s.size();i++){
        if(find(vow.begin(),vow.end(),s[i])!=vow.end())
        {
            s = s.replace(i,1,"");
            i--;
        }
    }
    return s;
}

```

### Minimum Parentheses
```

Given a string "pattern", which contains only two types of characters ‘(’, ‘)’.
Your task is to find the minimum number of parentheses either ‘(’, ‘)’ we must add 
the parentheses in string ‘pattern’ and the resulted string is valid.

Valid String :  
Every opening parenthesis ‘(’ must have a correct closing parenthesis ‘)’.
i/p :  )((() 
o/p : 3
Approach :
keep track of peranthesis by using a balance variable. 

* if balance == 0  valid string.
* if balance == -1 we have a closed paranthesis without it's corresponding opening paranthesis
* if balance>0 we have openened paranthesis but not closed.
balance will always be greater than -1;
```
```
initialize count =0 ;
we traverse array from left to right 
    => if we encounter '('  increment balance :  bal++
    => if we encounter ')'  decrement balance :  bal--
    => if bal==-1   (  that means we encountered ')' without any opened paranthesis before it )
          count++;  ( we have to add a opening paranthesis before it to make valid  )
          bal=0;    ( now it is balanced so we move to next part with perfectly balanced (bal=0)
          
return bal+count;

```
```
int minimumParentheses(string pattern) {
    int bal=0;
    int ans=0;
    for(char i: pattern){
        if(i=='(')
            bal+=1;
        else
            bal-=1;
        if(bal==-1){
            ans+=1;
            bal+=1;
        }
        
    }
    return  bal+ans;
}
```

