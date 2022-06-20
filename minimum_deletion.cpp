/*You are given a string s consisting only of characters 'a' and 'b'​​​​.
You can delete any number of characters in s to make s balanced. s is balanced if there is no pair of indices (i,j) such that i < j and s[i] = 'b' and s[j]= 'a'.
Return the minimum number of deletions needed to make s balanced.*/
#include<bits/stdc++.h>
using namespace std;

int minimumDeletions(string s) {
    int n=s.length();
    int cntA[s.length()],cntB[s.length()],a=0,b=0;
    cntA[0]=0; cntB[n-1]=0;
    for(int i=0;i<s.length();i++)
    {
        cntA[i]=b;
        if(s[i]=='b') b++;

    }
    for(int i=n-1;i>=0;i--)
    {
        cntB[i]=a;
        if(s[i]=='a') a++;
    }
    int ans=INT_MAX;
    for(int i=0;i<n;i++)
    {
        ans=min(ans,cntA[i]+cntB[i]);
    }
    return ans;
}

int main()
{

    string s;
    cin>>s;
    cout<<minimumDeletions(s)<<endl;
    return 0;
}
