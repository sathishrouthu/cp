# Strings
1. Strings are a sequence of characters. 
2. Two ways to represent:
  - char array
  - string object
  
**Declaration and Input**

1. By creating character arrays and treating them as a string

```
char str[6] = {'H', 'e', 'l', 'l', 'o', '\0'};

char[] str = "Hello";

cin.get(str,50);

```
But above method will give only input upto a fixed length say 50 chars

2.  By creating a string object

```
string str = "Hello world";

string s(6,'a');   //   this will be a string 6 a's concated together

getline(cin,str);


string must be declared with double quotes.
```

**Accessing**

str_name[index];

- Mutability of strings

Mutable data members whose values can be changed in runtime even if they are of a constant type.

To change the value of a specific character in a string, refer to the index number, and use single quotes.

str.front()  gives access to first character of the string 

str.front() = 'A'  this will change the first character to a letter A

similary str.back() also works


**Concatenation**

Can be done in 3 ways

* ‘+’ Operator
* strcat() method
* append() method

```
string new_string = string1 + string2;
```

C++ has a built-in method to concatenate strings. The strcat() method is used to concatenate strings in C++.

The strcat() function takes the char array as input and then concatenates the input values passed to the function.

strcat() function is included in the cstring library.

```
strcat(char array1, char array2);
```

append() method: 

C++ has another built-in method: append() to concatenate strings. The append() method can be used to add strings together.
It takes a string as a parameter and adds it to the end of the other string object.

```
string1.append(string2);
```

NOTE : We can also pushback method to append char at the end of the string.

String Comparison

- strcmp() method
- compare() method
- Relational Operators

The strcmp() function compares two strings in lexicographical manner.

```
int strcmp(const char * leftStr, const char * rightStr);
```

The return value from strcmp is 0 if the two strings are equal, less than 0 if str1 compares less than str2 , and greater than 0 if str1 compares greater than str2.


compare() method: C++ has in-built compare() function in order to compare two strings efficiently.

The compare() function compares two strings and returns the following values according to the matching cases:

-- Returns 0 if both the strings are the same.

-- Returns <0 if the first string’s character’s value is smaller than the second string input.

-- Returns >0 when the second string is greater in comparison.

```
str1.compare(str2);
```
```
>
<
==
>=
<=

s1 < s2: A string s1 is smaller than s2 string, if either, length of s1 is shorter than s2 or first mismatched character is smaller.
s1 > s2: A string s1 is greater than s2 string if either, length of s1 is longer than s2, or the first mismatched character is larger.
<= and >= have almost the same implementation with additional features of being equal as well.
==: If, after comparing lexicographically, both strings are found to be the same, then they are said to be equal.
!=: If any of the points from 1 to 3 follow up then, strings are said to be unequal.

```
**String Methods**

* str.size()  : return size
* reverse(str.begin(),str.end())  reverese the string inplace
* sort(str.begin(),str.end())     sort the string inplace





