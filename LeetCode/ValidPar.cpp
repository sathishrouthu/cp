
/*

Given a string s of '(' , ')' and lowercase English characters.

Your task is to remove the minimum number of parentheses ( '(' or ')', in any positions ) so that the resulting parentheses string is valid and return any valid string.

Formally, a parentheses string is valid if and only if:

It is the empty string, contains only lowercase characters, or
It can be written as AB (A concatenated with B), where A and B are valid strings, or
It can be written as (A), where A is a valid string.
 

Example 1:

Input: s = "lee(t(c)o)de)"
Output: "lee(t(c)o)de"
Explanation: "lee(t(co)de)" , "lee(t(c)ode)" would also be accepted.


*/




    string minRemoveToMakeValid(string s) {
        stack<int> stac;
        string ans="";
        for(int i=0;i<s.length();i++){
            if(s[i]=='(')
            {
                 stac.push(i);
            }
            else if(s[i]==')')
            {
                if(stac.empty())    s[i]='*';
                else stac.pop();
            }
        }
        while(!stac.empty()){
            s[stac.top()]='*';
            stac.pop();
        }
        for(int i=0;i<s.length();i++){
            if(s[i]=='*')
                continue;
            else
                ans+=s[i];
        }
        return ans;
    }
