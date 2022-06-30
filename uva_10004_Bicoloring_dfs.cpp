#include<bits/stdc++.h>
#define black 1
#define  red 2

using namespace std;

void add(int u, int v, vector<int> *edge){
    edge[u].push_back(v);
    edge[v].push_back(u);
}

void bfs(int x, int *color, bool *vis, vector<int> *edge){
    if(vis[x]) return;
    vis[x]= true;
    
    for(int i= 0; i<edge[x].size(); ++i){
        int u = edge[x][i];

        if(!vis[u]){
            if(color[x]==black) color[u]= red;
            else color[u] = black;
        }
        bfs(u,color,vis,edge);
    }


}

int main()
{
    int n;
    while(1){
        cin>>n;
        if(n==0) return 0;

        int m,u,v,flag=0;
        vector<int> edge[100006];
        bool vis[1000] = {0};
        int color [1000] = {0};

        cin>>m;
        for(int i=0; i<m; ++i)
        {
            cin>>u>>v;
            add(u,v,edge);
        }
        
        for(int i=0; i<n; ++i)
        {
            if(!vis[i])
            {
                color[i] = black;
                bfs(i, color, vis, edge);
            }
        }
        for(int i= 0; i<n; i++)
        {
            for(int j= 0; j<edge[i].size(); ++j)
            {
                if(color[i] == color[edge[i][j]])
                {
                    cout<< "NOT BICOLORABLE.\n";
                    flag=1;
                }
            }
            if(flag)break;
        }
        if(!flag) cout<<"BICOLORABLE.\n";

    }
}