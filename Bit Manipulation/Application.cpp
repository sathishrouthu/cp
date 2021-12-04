
/*
1. Check even or odd number 

n=10   -->  1 0 1 0    
                if the last bit (LSB) is 0 it means the remainder after first division while conversion from decimal to binary
                that means it is an even number. if the LSB is 1  the number is odd.
so the bitwise and with 1 will say whether the number is odd or even

if n&1==0 --> even          better than % operator 😁
else      --> odd

ex:
1 0 1 0 & 1  = 0  (even)
1 0 1   & 1  = 1  (odd)
 
  
2. calculate 2^n

if we want to calculate 2^n
Naive :
ans=1
for(i=1;i<=n;i++)
  ans*=2
it will take O(n)

if we use recursion O(logn) time 

but we can calculate by simple trick  with binary left shift :

2^n = 1<<n

in binary 2^n is n 0's left to the 1 🤷‍😉😉


*/



#include <bits/stdc++.h>
using namespace std;
#define sathish ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long int;
#define nl cout<<endl;
void solve()
{
    int n;
    cin>>n;
    cout<<"2^"<<n<<"  is :"<<(1<<n);
    nl
    if (n&1==1)
        cout<<"odd";
    else
        cout<<"even";
    nl
}

int main(){
    sathish
    int t=1;
    //cin >> t;
    while(t--){
    	solve();
    }
    return 0;
}
