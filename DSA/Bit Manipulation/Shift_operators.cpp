/*

Left Shift :

a<<b  : 
1.shift b bits of a to left
2.the number is multiplied by  2^b

ex :

a     : 1 0 0 1       (9)
a<<2  : 1 0 0 1 0 0   (36)


Right Shift :
1.shift(remove) b bits of a to left
2.the number is divided by  2^b

ex:

a     : 1 0 0 1       (9)
a>>2  : 0 0 1 0       (2)

 
*/

#include <bits/stdc++.h>
using namespace std;
#define sathish ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long int;
#define nl cout<<endl;
void solve()
{
	cout<<(10<<2);    // 10*2^2
    nl
    cout<<(50>>4);    // 50/2^4
    nl
    cout<<(10<<6);    // 10*2^6 
}

int main(){
    sathish
    int t=1;
    cin >> t;
    while(t--){
    	solve();
    }
    return 0;
}
