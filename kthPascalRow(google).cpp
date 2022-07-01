#include<bits/stdc++.h>

using namespace std;

vector<int>getRow(int k)
{
	vector<int>res;
	res.push_back(1);
     if(k==0) return res; //first row
	res.push_back(1);
     if(k==1) return res; //second row
     k=k-1; //first two row complete
     while(k--)
	{
		vector<int>temp;
		temp.push_back(1);
		for(int i=0;i<res.size()-1;i++)
             temp.push_back(res[i]+res[i+1]);
		temp.push_back(1);
		res=temp;
	}
     return res;
}

int main()
{
    cout<<"Enter the row value: ";
	int k;
 	cin>>k;
    vector<int>ans=getRow(k);
	for(auto it:ans)
       cout<<it<<" ";
	return 0;
}
