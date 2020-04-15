#include <bits/stdc++.h>
using namespace std;

#define MAX 10

int Time=1;
int sTime[MAX];
int fTime[MAX];

int n,e;  //decler global

vector <int> adj[MAX];
int visited[MAX];

void dfsvisit(int at)
{
    if(visited[at]!=0)
        return;
    visited[at]=1;
    //starting time calculate
    sTime[at]=Time;
    ++Time;

    for(int i=0; i<adj[at].size(); i++)
    {
        int v=adj[at][i];
        if(visited[v]==0)
        {
            dfsvisit(v);
        }
    }
    //finishing time calculate

    fTime[at]=Time;
    ++Time;

    //printing dfs
    cout<<at<<" ";
}


void dfs()
{
    for(int k=0;k<n;k++)
    {
        visited[k]=0;
    }
    cout<<"DFS:"<<" ";
    for(int i=0; i<n; i++)
    {
        if(visited[i]==0)
            dfsvisit(i);
    }
}

int main()
{
    int u,v;
    cout<<"Total number of Node: ";
    cin>>n;
    cout<<"Total number of edges: ";
    cin>>e;
    cout<<"Enter the input like(0--->1):"<<endl;
    for(int i=0; i<e; i++)
    {
        cin>>u>>v;
        adj[u].push_back(v);
    }

    dfs();

    cout<<endl;
    cout<<"Starting and Finishing time is:"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<i<<"--->"<<sTime[i]<<"/"<<fTime[i]<<endl;
    }

    return 0;
}
