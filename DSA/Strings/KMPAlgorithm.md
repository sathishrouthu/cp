### Knuth Morris Pratt Pattern Searching Algoithm:

Given a String Text and another String Pattern, Check if the Given Pattern exists in the Text or not ? 

Ex: 

Given Text = "ABCBABABAC"  Pattern = "ABA"  output : Pattern exists at index 4.

Given Text = "SUNRISERS" Pattern = "RISE"  output : Pattern exists at index 3.

Naive Approach : 

For each index in the text check if Pattern exists from this index, if not exists go to next index in the text and repeat.

```
for int i --> 0 to TextLength-1:
    for int j --> 0 to PatternLenght-1:
          if(text[i+j] != pattern[j])
                break;
    if(j==patternLength)
          return i;
return -1;
```

In above naive approach, while comparing pattern and text,  
whenever we found a mismatch ( text[i+j] != pattern[j] ) then  
we are going back to next position in text to compare,  
for example :  
Given  
text = "TRAILTRAIN"  
Pattern = "TRAIN"  
When we found a Mismatch at 'L' in the text with the Pattern's 'N'  
in next iteration we are going to compare from 'R', this going back again is making the naive approach slow,  
we already compared till 'L' and then we are again comparing them, instead of completely going back, we can start comparin from Mismatch  
such that we can start comparing from T itself, Now we have the entire pattern matching.  
But in above example we totally ignored all the previously matching characters. this wont work in some other examples:  
lets say :  
Text = "ONIONIONSPL"  
Pattern = "ONIONS"  

now first mismatch occurs at 5th index in the Text.
so, if we start comparing from here we will miss the answer.  
that is because if the previously matched text has same prefix and suffix.
so we have to move the index to the 'O' at index 3 instead of 'I' at index 5 and start comparing from 3.

how to know where to move when a mismatch occurs, we need to go to the position where the common prefix and suffix of the pattern exists.  
for this we need to pre- calculate the Longest Proper Prefix and Suffix array.  
~proper prefix/suffix means, entire string cannot be considered.  
for example string "abcde" have proper prefixes : a, ab, abc, abcd but not ~abcde~  
this tells us, for each index i in pattern, the length of the longest proper prefix and suffix length.

for example LPS array of given string : "ONIONS" is :  
[ 0, 0, 0, 1, 2, 0 ] 

Algorithm : 
```
KMPSearch ( String Text, String Pattern ) :
        n = Text Length
        m = Pattern Length
        LPS = array of size M
        compute Lps array 
        int j = 0;
        while i <= N-M+1 :
            // Matched character, move forward
            if pattern[j] == text[i+j]
                i++;
                j++;
            // Mismatched character, set J to Longest prefix and suffix for index j-1
            // which means we need to start our next comparsion of pattern from the longest prefix suffix of pattern[0..j-1]
            else
                // but if and only if j != 0 or else we dont have a prefix or suffix and j is 0, so we just need move forward with i.
                if (j!=0) 
                    j = lps[j-1]
                else
                    i++;
            if(j==m) // pattern found in text
                print ( "pattern found at i-j )
                j = lps[j-1] //  reset j to previous index's longest prefix and suffix.
```
How to compute LPS Array ?  
we want to find the index for each substring where it's longest prefix and also siffix ends.  
example for given array : 
```
" ONIONIONSPL "
LPS = [ 0 0 0 0 0 0 0 0 0 0 0 ]
index i = 0 : prefix and also suffix doesnot exists LPS[0] = 0
index i = 1 : prefix and also suffix doesnot exists LPS[1] = 0
index i = 2 : prefix and also suffix doesnot exists LPS[2] = 0
index i = 3 : prefix and also suffix is "O" which has length : 1,  LPS[3] = 1
index i = 4 : prefix and also suffix is "ON" which has length : 2, LPS[4] = 2
.
.
.
.

```
Algorithm : 
```
computeLPS(String str ): 
    N = length of given string
    we initialize two variables :  
    len = 0  ( tells the current length of the prefix and suffix )
    i = 1    ( for iterating the string to find matches with prefix or suffix )
    LPS[0] = 0 ( there is no proper prefix/suffix for single character)
    while (i < N ):
        if (str[i] == str[len] )
            // Match found, it means current character is a prefix and suffix for the substring str[len ... i ];
            LPS[i] = len+1;
            i++;
            len++;
        else:
            // Match not found, means we lost the matching continuity and we have to reset len to previous longest prefix and suffix
            // but if len == 0  means we dont have to reset len anymore, just move forward with i
            if(len != 0 )
                len = LPS[len-1]
            else
                // Match doesnot occur at all in the substring str[0...i], so there is longest prefix and suffix at current index
                lps[i] = 0;
                i++;
```

```
class Solution
{
    ArrayList<Integer> search(String pat, String txt)
    {
        char[] pattern = pat.toCharArray();
        char[] text = txt.toCharArray();
        int n = text.length;
        int m = pattern.length;
        ArrayList<Integer> result = new ArrayList<Integer>();
        int[] lps = new int[m];
        // Compute LPS
        int len = 0;
        int i=1;
        while(i<m){
            if(pattern[i] == pattern[len]){
                lps[i] = len+1;
                i++;
                len++;
            }
            else{
                if(len!=0){
                    len = lps[len-1];
                }
                else{
                    lps[i] = 0;
                    i++;
                }
            }
        }

        // Search for pattern using LPS
        i = 0;
        int j = 0;
        while(i<n){
            if(text[i] == pattern[j]){
                i++;
                j++;
            }
            else{
                if(j!=0)
                    j = lps[j-1];
                else
                    i++;
            }
            if(j==m){
                result.add(i-j + 1);
                j = lps[j-1];
            }
        }
        return result;
    }
}
```





            
