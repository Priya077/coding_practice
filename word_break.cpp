/*Given a string s and a dictionary of strings wordDict, return true if s can be segmented into a space-separated sequence of one or more dictionary words.
Note that the same word in the dictionary may be reused multiple times in the segmentation.*/


#include<bits/stdc++.h>

using namespace std;

 bool wordBreak(string s, vector<string> &dict) {
        if(dict.size()==0) return false;  //empty dictionary
        int n=s.length();
        int dp[n+1];
        memset(dp,0,sizeof(dp));
        dp[0]=true; //no character means it is true i.e base case

        for(int i=1;i<=n;i++)
        {
            for(int j=i-1;j>=0;j--)
            {
                if(dp[j]==1)
                {
                    //string word = s.substr(j,i-j);
                    if(find(dict.begin(),dict.end(),s.substr(j,i-j))!= dict.end())
                    {
                        dp[i]=true;
                        break; //next i
                    }
                }
            }
        }

        return dp[n];
    }

int main()
{

    vector<string>dict;
    string s,t;
    cin>>s;
    int N;
    cin>>N;
    for(int i=0;i<N;i++)
    {

        cin>>t;
        dict.push_back(t);
    }
    cout<<wordBreak(s,dict)<<endl;
}
