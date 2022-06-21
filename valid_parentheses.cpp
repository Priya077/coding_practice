#include<bits/stdc++.h>

using namespace std;

bool validParentheses(string s) {
    stack<char>st;
    int len=s.length();
    for(int i=0;i<len;i++)
    {
        if(s[i]=='(' || s[i]=='{' || s[i]=='[')
            st.push(s[i]);
        else{

            if(!st.empty()){
                char c=st.top();
                if((s[i]==')' && c=='(') ||(s[i]==']' && c=='[') ||(s[i]=='}' && c=='{'))
                   st.pop();
                else return false; }
            else st.push(s[i]);
        }
    }
    if(!st.empty()) return false;
    return true;
}

int main()
{

    string s;
    cin>>s;
    cout<<validParentheses(s)<<endl;
    return 0;
}
