
### Shortest Substring with all characters

You have been given a string 'S' which only consists of lowercase English-Alphabet letters. Your task is to find the shortest (minimum length) substring from 'S' which contains all the characters of 'S' at least once.

If there are more than one substring with the shortest length, then find one which appears earlier in the string ‘S’ i.e. substring whose starting index is lowest.

**Brute force approach**

* count all the distinct characters in the given string and store it in the "DIST".
* we try to generate all possible substring by using a nested for loops
* from now generate a substring and check for
* if the no. of characters in substring equals to the "DIST".
* check the length of current substring and compare with previous min_length and note the starting index.
```
dist = distinct characters.
start=0;
min_length = INT_MAX;
for i-->0 to n-1
  Set = {};
  for j-->i to n-1
     Set.insert(str[j]);
     if (Set.size()==dist)
         if( j-i < min_length )
               min_length = j-i;
               start = i;
return str.substr(start,minlength+1);

```

```
#include<bits/stdc++.h>
string shortestSubstring(string s)
{
    // Write your code here.
    int n = s.length();
    unordered_set<char> Set;
    for( char i : s)
        Set.insert(i);
    int dist = Set.size();
    int start,min_length=INT_MAX;
    for(int i=0;i<n;i++){
        Set = {};
        for(int j=i;j<n;j++){
            Set.insert(s[j]);
            if(Set.size()==dist){
                if(j-i < min_length){
                    start = i;
                    min_length = j-i;
                }
            }
        }
    }
    return s.substr(start,min_length+1);
    
}

```

**Efficient Approach**
```
- Use two pointers i and j to keep a window as substring and then we use this window to satisfy our conditions

- initialize a hash set (freq) of <char,int> to keep track of no.of dist characters in our window.
- there are two main operations to be performed on window:
=> expand window : increase freq of new character of window in hashset and j++;
=> shrink window : decrease freq of starting character of window in hashset and i++;

- we expand the window until we find a substring that contains all characters of whole string.
- if we find such substring we update the results and  try to shrink the window to get minimum length.

```

```
- count no. of distinct characters in given string by using a set and store it in distinct.
- Initialize empty hashset
- Initialize i=0,j=0,start=0,min_length = n;
- while(j<n)
     freq[str[j]]++;
     while(freq.size()==distinct)
           if(j-i < min_length)
                min_length = j-i
                start=i
           freq[str[i]]--;
           if(freq[s[i]]==0)
               freq.erase(s[i])
           i++;
     j++
- return str.substr(start,min_length+1);     
```

```
#include<bits/stdc++.h>
string shortestSubstring(string s)
{
    int n = s.length();
    int start = 0,i=0,j=0,min_length = n;
    unordered_set<int> Set;
    for(char i:s)
        Set.insert(i);
    int dist = Set.size();
    unordered_map<char,int> freq;
    int count=0;
    while(j<n){
        freq[s[j]]++;
        while(freq.size()==dist){
            if(j-i < min_length){
                min_length = j-i;
                start = i;
            }
            freq[s[i]]--;
            if(freq[s[i]]==0)
                freq.erase(s[i]);
            i++;
        }
        j++;
    }
    return s.substr(start,min_length+1);
}

// Java Code

public static String shortestSubstring(String s) {
		int n = s.length();
		Set<Character> set = new HashSet<>();
		for(char c : s.toCharArray()) set.add(c);
		int distinct = set.size();
		HashMap<Character,Integer> map = new HashMap<>();
		int start = 0,end = n-1;
		int i = 0,j=0;
		while(j<n){
			map.put(s.charAt(j),map.getOrDefault(s.charAt(j), 0)+1);
			while(map.size()==distinct){
				if(j-i < end-start){
					start = i;
					end = j;
				}
				map.put(s.charAt(i), map.get(s.charAt(i))-1 );
				if(map.get(s.charAt(i)) == 0) 
						map.remove(s.charAt(i));
				i++;
			}
			j++;
		}
		return s.substring(start, end+1);
	}
```



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
	public static int kDistinctChars(int k, String str) {
		int n = str.length();
		int maxLength = 0;
		int i = 0, j = 0;
		HashMap<Character,Integer> map = new HashMap<>();
		while(j < n){
			map.put(str.charAt(j) , map.getOrDefault(str.charAt(j),0)+1);
			while( map.size() > k){
				map.put(str.charAt(i), map.get(str.charAt(i))-1);
				if(map.get(str.charAt(i)) == 0)
					map.remove(str.charAt(i));
				i++;
			}
			maxLength  = Math.max(maxLength, j-i + 1);
			j++;
		}
		return maxLength;
	}

```




### Minimum Window Substring
You are given two strings ‘A’ and ‘B’. Your task is to return a substring ‘S’ of ‘A’ such that the following conditions hold true :

- You can make ‘B’ from ‘S’ by removing some characters and rearranging some characters zero or more times.
- Length of ‘S’ must be as minimum as possible.
Note :
Testcases are generated such that a substring always exists and is unique.

Example :

A = ninjas, B = sin

All possible substrings with which 'B' can be created are
"ninjas", "injas".

Hence the substring with minimum length is "injas".

```
public class Solution {
    public static String minSubString(String a, String b) {
        int n = a.length();

        // To maintain answer
        int start = 0, end = n;

        // Two pointers to iterate the String A
        int i = 0, j = 0;

        // To keep track of required letters from substring to form String B
        int need = b.length();

        // to keep track of all the letters from B and letters encountered in A
        int[] freq = new int[26];

        // Initialize with frequency of characters in B
        for(int k=0;k<b.length();k++){
            freq[b.charAt(k) - 'a']++;
        }

        while(j < n){
            // we encountered a character in A,
            //So, we need to decrease it's frequency in freq array
            freq[a.charAt(j)-'a']--;
            // even after decreasing, if it's frequency is still >= 0 means, this characters is present in B, so it is one of needed character
            if(freq[a.charAt(j)-'a'] >=0)
            // now decrease the need as we encountered a character which presents in B
                need--;

            // if need became 0 means, we obtained a substring from A, which had all the needed characters to form B
            // now we need to shrink the window from left to get minimum possible substring.
            while(need==0){
                // Update the answer
                if(j-i < end-start){
                    end = j;
                    start = i;
                }
                // since we are moving window to the left, previously we have reduced the freq of a[i], now we need to increase it.
                // it means that, we have not included the a[i] in substring from now.
                freq[a.charAt(i)-'a']++;
                // even after increasing if the need is still > 0 it means it is one of the character from B.
                if(freq[a.charAt(i)-'a'] > 0)
                // since we removed the required character to form B, we have to increase the need;
                    need++;
                i++;
            }
            j++;
        }
        if(end==n) return "-1";
        return a.substring(start,end+1);
    }
}
```
