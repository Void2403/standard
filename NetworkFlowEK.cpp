#include <cstdio>
#include <cstring>
#define fillchar(a) memset(a,0,sizeof(a))
#define max(a,b) a>b?a:b
#define min(a,b) a<b?a:b

using namespace std;

int n,T,edge[220][220];
int pre[1100],vis[1100],q[510000],head,tail,flag;
int MaxFlow=0,aug=0,ans;

inline int read()
{
	int x=0;char c=getchar();
	while(c<'0' ||c>'9')c=getchar();
	while(c>='0' && c<='9')x=(x<<1)+(x<<3)+(c^48),c=getchar();
	return x;
}

// void add(int fr,int to,int val){e[++cnt]=(edge){to,late[fr],val};late[fr]=cnt;}

int bfs()
{
	fillchar(pre);fillchar(vis);
	pre[1]=0;vis[1]=1;
	q[1]=1;head=0;tail=1;flag=0;
	int now,go;
	while(head<tail)
	{
		now=q[++head];
		for(int i=1;i<=T;i++)
			if(!vis[i] && edge[now][i]>0)
			{
				pre[i]=now;vis[i]++;
				if(i==T){flag++;tail=-1;break;}
				else q[++tail]=i;
			}
	}
	return flag;
}

int augment()
{
	if(bfs())
	{
		int minflow=1<<30;
		int now=T;
		while(pre[now])minflow=min(minflow,edge[pre[now]][now]),now=pre[now];
		now=T;
		while(pre[now])
		{
			edge[pre[now]][now]-=minflow;
			edge[now][pre[now]]+=minflow;
			now=pre[now];
		}
		return minflow;
	}
	return 0;
}

int main()
{
	freopen("ditches.in","r",stdin);
	n=read();T=read();
	for(int i=1;i<=n;i++)
	{
		int u=read(),v=read(),w=read();
		edge[u][v]+=w;
	}
	while(aug=augment())MaxFlow+=aug;
	printf("%d",MaxFlow);
	return 0;
}
