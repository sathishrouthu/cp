#include<bits/stdc++.h>
using namespace std;
bool isEqual(vector<int> &arr1,vector<int> &arr2){
        for(int i=0;i<26;i++)
            if(arr1[i]!=arr2[i])
                return false;
        return true;
    }
bool checkInclusion(string s1, string s2) {
    vector<int> arr1(26,0);
    vector<int> arr2(26,0);
    int m = s1.length();
    int n = s2.length();
    for(int i=0;i<m;i++){
        arr1[s1[i]-'a']++;
    }

    int i=0,j=0;
    while(j<n){
        while(j-i < m && j<n){
            arr2[s2[j]-'a']++;
            j++;
        }
        if(isEqual(arr1,arr2))
            return true;
        arr2[s2[i]-'a']--;
        i++;
    }
    return false;
}

int main(){
    string s1 = "scs";
    string s2 = "defabcss";
    cout<<checkInclusion(s1,s2);
    return 0;
}
