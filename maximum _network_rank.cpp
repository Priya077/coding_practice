/* Problem statement:  There is an infrastructure of n cities with some number of roads connecting these cities. Each roads[i] = [ai, bi] indicates that there is a bidirectional road between cities ai and bi.
The network rank of two different cities is defined as the total number of directly connected roads to either city. If a road is directly connected to both cities, it is only counted once.
The maximal network rank of the infrastructure is the maximum network rank of all pairs of different cities.
Given the integer n and the array roads, return the maximal network rank of the entire infrastructure.*/



#include<bits/stdc++.h>
using namespace std;

int maximalNetworkRank(int n, vector<vector<int>>& roads) {
     vector<unordered_set<int>>adj(n);
     for(auto it:roads) // creating the graph
     {
       adj[it[0]].insert(it[1]);
       adj[it[1]].insert(it[0]);
     }
     int max_rank=0;
     for(int i=0;i<n;i++)
     {
        for(int j=i+1;j<n;j++)
        {
          int rank=adj[i].size()+adj[j].size();
          if(adj[j].count(i)) rank--; // if there is a direct connection , reducing rank by one to avoid double count
          max_rank=max(max_rank,rank);
        }

     }
        return max_rank;

    }

int main()
{
    //we can also take input from the user 
    int n=5;
    vector<vector<int>>roads={{0,1},{0,3},{1,2},{1,3},{2,3},{2,4}};
    cout<<maximalNetworkRank(n,roads)<<endl;
    return 0;
}
