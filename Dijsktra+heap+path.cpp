#include<cstdio>
#include<cstring>
#include<iostream>
#include<queue>
#include<vector>
#define INF 2147483647

using namespace std;
int n,m,cnt=0,start,endd,dis[110000],vis[110000],b[110000],path[110000],print[110000];
struct map
{
	int to,val,last;
}a[550000];
struct cmp
{
    bool operator()(int a,int b)
    { 
        return dis[a]>dis[b];
    } 
};

inline int read()
{
	int x=0,f=0; char c=getchar();
	while (c<'0' || c>'9') f=(c=='-') ? 1:f,c=getchar();
	while (c>='0' && c<='9') x=(x<<1)+(x<<3)+(c^48),c=getchar();
	return f ? -x:x;
}

void add(int fr,int tow,int len)
{
	a[++cnt]=(map){tow,len,b[fr]};b[fr]=cnt;
}

void dij(int start)
{
	priority_queue<int,vector<int>,cmp> Q;
	for(int i=0;i<=n;i++)dis[i]=INF;
	memset(vis,0,sizeof(vis));
	dis[start]=0;
	Q.push(start);
	int now,got;
	while(!Q.empty())
	{
		now=Q.top();
		Q.pop();
		vis[now]=0;
		for(int i=b[now];i>0;i=a[i].last)
		{
			got=a[i].to;
			if(dis[got]==INF || dis[got]>dis[now]+a[i].val)
			{
				dis[got]=dis[now]+a[i].val;
				path[got]=now;
				if(!vis[got])
				{
					vis[got]=1;
					Q.push(got);
				}
			}
		}
	}
}

int main()
{
	n=read();m=read();start=read();endd=read();
	for(int i=1;i<=m;++i)
	{
		int x,y,len;
		x=read(),y=read(),len=read();
		add(x,y,len);
	}
	dij(start);
	cnt=0;
	for(int i=path[endd];i;i=path[i])print[++cnt]=i;
	for(int i=cnt;i>=1;--i)printf("%d ",print[i]);//记录路径
	return 0;
}