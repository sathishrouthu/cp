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

