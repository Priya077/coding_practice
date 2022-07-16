#include<bits/stdc++.h>
using namespace std;

int findMajority(int arr[],int N)
{
    int cnt=0,ele=-1;
    for(int i=0;i<N;i++)
    {

        if(cnt==0){ ele=arr[i]; cnt=1; }
        else if(arr[i]==ele) cnt++;
        else cnt--;
    }
    int cnt1=0;
    for(int i=0;i<N;i++)
    {
     if(arr[i]==ele) cnt1++;
    }
    if(cnt1>N/2) return ele;
    else return -1;
}
int main()
{
    int N;
    cin>>N;//size of array
    int arr[N];
    for(int i=0;i<N;i++) cin>>arr[i];
    cout<<findMajority(arr,N)<<endl;
    return 0;
}
