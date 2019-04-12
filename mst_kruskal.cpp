#include <cstdio>
#include <algorithm>

using namespace std;

int n,m,ans,father[5100],tot=0;
struct mst
{
	int fr,to,val;
}e[220000];

inline int read()
{
	int x=0;char c=getchar();
	while(c<'0' || c>'9')c=getchar();
	while(c>='0' && c<='9')x=(x<<1)+(x<<3)+(c^48),c=getchar();
	return x;
}

bool cmp(mst a,mst b){return a.val<b.val;}

int getfather(int x)
{
	if(father[x]!=x)father[x]=getfather(father[x]);
	return father[x];
}

void modify(int x,int y)
{
	x=getfather(x),y=getfather(y);
	father[y]=x;
}

void kruskal()
{
	sort(e+1,e+m+1,cmp);
	for(int i=1;i<=m;i++)
	{
		int U=getfather(e[i].fr),V=getfather(e[i].to);
		if(U!=V){modify(U,V);ans+=e[i].val;if(++tot==m-1)break;}
	}
}

int main()
{
	n=read(),m=read();
	for(int i=1;i<=m;i++)
		e[i].fr=read(),e[i].to=read(),e[i].val=read();
	for(int i=1;i<=n;i++)father[i]=i;
	kruskal();
	printf("%d",ans);
	return 0;
}