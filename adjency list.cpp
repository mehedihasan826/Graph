#include<bits/stdc++.h>

#define maxi 10000
using namespace std;


void add(int u, int v, vector<int> *edge)
{
    edge[u].push_back(v);
    edge[v].push_back(u);
}

int main (){
    int t=0;
    if(!t)cout<<"1";
    else cout<<"0";

    int n,m;
    cin>>n>>m;
    int u,v;
    vector<int> edge[maxi];
    for(int i=1;i<=m; ++i)
    {
        cin>>u>>v;
        add(u,v,edge);
    }

    for(int i=1; i<=n; i++){
            cout<<edge[i].size()<<endl;
        for(int j=0;j<edge[i].size();j++){
                printf("vartex of %d are %d \n", i, edge[i][j]);
        }
        cout<<endl;
    }

}
