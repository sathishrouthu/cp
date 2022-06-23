### Longest Sub-string With atmost K Distinct Characters

You are given a string 'S' of length 'N' consisting of lowercase English alphabet letters. You are also given a positive integer 'K'.
Now, a substring of this string is good if it contains at most 'K' distinct characters. 

A string 'X' is a substring of string 'Y' if it can be obtained by deletion of several continuous elements(possibly zero) from the beginning and the end from the string 'Y'.

Your task is to return the maximum size of any good substring of the string 'S'.

```
‘S’ = “bacda” and ‘K’ = 3.
So, the substrings having at most ‘3’ distinct characters are called good substrings. Some possible good substrings are:
1. “bac”
2. “acd”
3. “acda”
The substring “acda” is the largest possible good substring, as we cannot get any other substring of 
length 5 or more having distinct characters less than or equal to ‘3’.
Thus, you should return ‘4’ as the answer.
```
* start with a left pointer as start=0 and right pointer j=0 of a sliding window.
* increase  the right pointer until we exhasust k distinct characters that means we expand window while we have atmost k distinct characters.
* when we have more than k distinct characters we decrease the window size from left.

```
#include<bits/stdc++.h>
int getLengthofLongestSubstring(string s, int k) {
    int n=s.length();
    int start=0;
    int longest=0;
    unordered_map<char,int> st;
    int j=0;
    while(j<n){
        st[s[j]]++;
        if(st.size()<=k)
            longest = max(longest,j-start);
        while(st.size()>k){
            st[s[start]]--;
            if(st[s[start]]==0)
                 st.erase(s[start]);            
            start++;
        }
        j++;
    }
    return 1+longest;
}

```

