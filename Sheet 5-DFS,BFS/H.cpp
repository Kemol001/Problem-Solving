#include<iostream>
#include<stdio.h>
#include<queue>
using namespace std;

int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
string s[1005];
int d[1005][1005];
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
        cin>>s[i];
    pair<int,int> now;
    pair<int,int> goal;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            d[i][j]=1005*1005;
            if(s[i][j]=='E')
            {
                now.first = i;
                now.second = j;
                d[i][j]=0;
            }
            if(s[i][j]=='S')
            {
                goal.first = i;
                goal.second = j;
            }
        }
    }
    queue<pair<int,int> > Q;
    Q.push(now);
    while(!Q.empty())
    {
        now = Q.front();
        Q.pop();
        for(int i=0;i<4;i++)
        {
            pair<int,int> next = now;
            next.first += dx[i];
            next.second += dy[i];
            if(next.first<0||next.first>=n)
                continue;
            if(next.second<0||next.second>=m)
                continue;
            if(s[next.first][next.second]=='T')
                continue;
            if(d[next.first][next.second] > d[now.first][now.second] + 1)
            {
                d[next.first][next.second] = d[now.first][now.second] + 1;
                Q.push(next);
            }
        }
    }
    int ans = 0;
    int pp = d[goal.first][goal.second];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            //cout<<d[i][j]<<" ";
            if(s[i][j]<='9'&&s[i][j]>='0'&&d[i][j]-1<pp)
            {
                ans += s[i][j]-'0';
            }
        }
        //cout<<endl;
    }
    printf("%d\n",ans);
}