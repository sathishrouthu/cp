class Solution {
public:
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
};
