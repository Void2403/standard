#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

int ans,a[100000],f[400000],n,m;

inline int read()
{
	int x=0;char c=getchar();
	while(c<'0' || c>'9')c=getchar();
	while(c>='0' && c<='9')x=(x<<1)+(x<<3)+(c^48),c=getchar();
	return x;
}

void build(int x,int l,int r)
{
	int mid;
	if (l==r) f[x]=a[l];
	else
	{
		mid=(l+r)/2;
		build(2*x,l,mid);
		build(2*x+1,mid+1,r);
		f[x]=max(f[2*x],f[2*x+1]);	
	}
}

void modify(int k,int l,int r,int x,int y)
{
	int mid;
	if (l==r) f[k]=y;
	else
	{
		mid=(l+r)/2;
		if (x<=mid) modify(k*2,l,mid,x,y); else modify(k*2+1,mid+1,r,x,y);
		f[k]=max(f[2*k],f[2*k+1]);
	}
}

void query(int k,int l,int r,int x,int y)
{
	int mid;
	if (l==x && r==y) ans=max(f[k],ans); else 
	{
		mid=(l+r)/2;
		if (y<=mid) query(k*2,l,mid,x,y);else if (x>mid) query(k*2+1,mid+1,r,x,y);
		if (x<=mid && y>mid) 
		{
			query(k*2,l,mid,x,mid);
			query(k*2+1,mid+1,r,mid+1,y);	
		}
	}
}

int main()
{
	n=read();
	for (int i=1;i<=n;i++)a[i]=read();
	memset(f,0,sizeof(f));
	build(1,1,n);
	m=read();
	for (int i=1;i<=m;i++)
	{
		int z=read(),x=read(),y=read();
		if (z==1) modify(1,1,n,x,y); 
		else
		{
			ans=-99999999;
			query(1,1,n,x,y);
			printf("%d\n",ans);
		}
	}
	return 0;
}