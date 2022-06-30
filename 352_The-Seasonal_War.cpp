#include <bits/stdc++.h>
using namespace std;

int vis[30][30];
vector<string> image;
int dx[] = {-1,-1,-1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1,-1, 1,-1, 0, 1};

void dfs(int i, int j, int n)
{
    if(vis[i][j])
    {
      //  printf("returning\n");
        return;
    }

    vis[i][j] = 1;
  //  printf("visited\n");

    for (int a = 0; a < 8; a++)
    {
        int x = i + dx[a];
        int y = j + dy[a];

        if (x >= 0 && x < n && y >= 0 && y < n && !vis[x][y])
        {
            if (image[x][y] == '1')
            {
               // printf("dfs called %d %d\n", x,y);
                dfs(x, y, n);
            }
        }
    }
}

int main()
{
 //   freopen("in.txt","r",stdin);
 //   freopen("out.txt","w",stdout);
    int i, j, n, t = 1;
    while (scanf("%d",&n)!= EOF)
    {
        image.clear();
        memset(vis, 0, sizeof(vis));
        string s;
        int cnt = 0;
        for (i = 0; i < n; i++)
        {
            cin >> s;
            image.push_back(s);
        }

        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                if (!vis[i][j])
                {

                    if (image[i][j] == '1')
                    {
                        cnt++;
                      //  printf("return execute %d %d cnt %d\n",i,j,cnt);
                        dfs(i, j, n);
                    }
                }
            }
        }
        printf("Image number %d contains %d war eagles.\n",t++,cnt);
    }
}
