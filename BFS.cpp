#include<iostream>
#include<queue>
using namespace std;

#define SZ 100
int g[SZ][SZ];
int dis[SZ];
int par[SZ];
char col[SZ];
void BFS(int source);

int main()
{
    int nodes,i,j;
    //cout<<"Enter total numbers of node : "<<endl;
    //cin>>nodes;
    cout<<"Nodes are 1 to 4"<<endl;
    for(i=1;i<=6;i++)
    {
        for(j=1;j<=6;j++)
        {
            g[i][j]=0;
        }
    }
    for(i=1;i<=6;i++)
    {
        for(j=1;j<=6;j++)
        {
            cout<<g[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    int a,b,edges;
    cout<<"Enter number of edges : "<<endl;
    cin>>edges;
    for(i=1;i<=edges;i++)
    {
        cin>>a>>b;
        g[a][b]=1;
        g[b][a]=1;
    }
    for(i=1;i<=6;i++)
    {
        for(j=1;j<=6;j++)
        {
            cout<<g[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    BFS(1);
    return 0;
}

void BFS(int source)
{
    int i;
    queue<int> q;
    for(i=0;i<=6;i++)
    {
        dis[i]=-1;
        par[i]=-1;
        col[i]='W';
    }
    dis[source]=0;
    par[source]=-1;
    col[source]='G';
    q.push(source);

    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(i=1;i<=6;i++)
        {
            if(g[u][i]==1)
            {
                if(col[i]=='W')
                {
                    col[i]='G';
                    par[i]=u;
                    dis[i]=dis[u]+1;
                    q.push(i);
                }
            }
        }
        col[u]='B';
    }
    for(i=1;i<=6;i++)
    {
        cout<<"Node : "<<i<<"\t"<<"Parent : "<<par[i]<<"\t"<<"Distance : "<<dis[i]<<"\t"<<"Color : "<<col[i]<<endl;
    }
}
