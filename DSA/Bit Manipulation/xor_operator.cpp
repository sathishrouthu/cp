/*
xor :

1 0 1 0
0 0 1 1
--------
1 0 0 1


0 xor 0 : 0     ----
                    |
0 xor 1 : 1 ---     |-----> xor with 0 makes no change 
              |     |
1 xor 0 : 1   | ----
              |-----------> xor with 1 makes toggled that is change 
1 xor 1 : 0 --|


xor needs variety..!

Properties :

a xor 0 : a
              ( 0 doesn't make any difference !)
a xor a : 0

a xor 1 : a'


*/ 

/*
Problem : in given array A find the only element that occuring only once. (given each element occurs twice )
 example  : array :  2 6 7 6 2    answer : 7

Bruteforce not allowed , sorting not allowed , frequency counting not allowed 
solution should be found in single iteration ..!!!!!

*/
/*

Solution :

if we xor all the elements in the array . the elements occuring twice will be cancelled each other and 
becomes 0 , because of "  a xor a = 0  " 
and finally the single element will be xor'ed with 0 and results itself.

*/

#include<bits/stdc++.h>
using namespace std;
int main()
{
int n,e;
cin>>n;
int ans=0;
while(n--)
{
  cin>>e;
  ans=ans^e;
}
cout<<ans;
}
