#include <cstdio>
#include <cstring>
#define max(a,b) a>b?a:b
#define MAXN 110000

using namespace std;

int n,m,p,lazy[MAXN

	<<3|1],f[MAXN<<3|1],a[MAXN],ans,opt,x,y,c;

inline int read()
{
	int x=0,f=1;char c=getchar();
	while(c<'0' || c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0' && c<='9')x=(x<<1)+(x<<3)+(c^48),c=getchar();
	return x*f;
}

void build(int t,int l,int r)
{
	if(l==r){f[t]=a[l];return;}
	int mid=l+r>>1;
	build(t<<1,l,mid);
	build(t<<1|1,mid+1,r);
	f[t]=max(f[t<<1],f[t<<1|1]);
	// f[t]=f[t<<1]+f[t<<1|1];
}

void pushdown(int t,int l,int r)
{
	if(!lazy[t])return;
	f[t]+=lazy[t];
	// f[t]+=lazy[t]*(r-l+1);
	lazy[t<<1]+=lazy[t];
	lazy[t<<1|1]+=lazy[t];
	lazy[t]=0;
}

void modify(int t,int l,int r,int x,int y,int c)
{
	pushdown(t,l,r);
	if(l==x && r==y){lazy[t]+=c;return;}
	int mid=l+r>>1;
	if(y<=mid)
		modify(t<<1,l,mid,x,y,c);
	else
		if(x>mid)
			modify(t<<1|1,mid+1,r,x,y,c);
		else
		{
			modify(t<<1,l,mid,x,mid,c);
			modify(t<<1|1,mid+1,r,mid+1,y,c);
		}
	pushdown(t<<1,l,mid),pushdown(t<<1|1,mid+1,r);
	f[t]=max(f[t<<1],f[t<<1|1]);
	//f[t]=f[t<<1]+lazy[t<<1]+f[t<<1|1]+lazy[t<<1|1];
}

/*void modify(int t,int l,int r,int x,int c)
{
	int mid;
	if (l==r) f[t]+=c;
	else
	{
		mid=(l+r)/2;
		if (x<=mid) modify(t<<!,l,mid,x,y); else modify(t<<1|1,mid+1,r,x,y);
		f[k]=max(f[t<<1],f[t<<1|1]);
	}
}*/

/*void query(int t,int l,int r,int x,int y)
{
	pushdown(t,l,r);
	if(l==x && r==y){ans=max(ans,f[t]);return;}//ans+=f[t];
	int mid=(l+r)/2;
	if(y<=mid)
		query(t<<1,l,mid,x,y);
	else
		if(x>mid)
			query(t<<1|1,mid+1,r,x,y);
		else
		{
			query(t<<1,l,mid,x,mid);
			query(t<<1|1,mid+1,r,mid+1,y);
		}
}*/

int query(int t,int l,int r,int x,int y)
{
	pushdown(t,l,r);
	if(l==x && r==y)return f[t];
	int mid=l+r>>1;
	if(y<=mid)return query(t<<1,l,mid,x,y);
	else
		if(x>mid)return query(t<<1|1,mid+1,r,x,y);
		else
			return max(query(t<<1,l,mid,x,mid),query(t<<1|1,mid+1,r,mid+1,y));
			//return query(t<<1,l,mid,x,mid)+query(t<<1|1,mid+1,r,mid+1,y);
}

int main()
{
	freopen("segmenttree.in","r",stdin);freopen("C:\\Users\\Administrator\\Desktop\\1.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	build(1,1,n);m=read();
	memset(lazy,0,sizeof(lazy));
	// memset(f,0,sizeof(f));
	for(int i=1;i<=m;i++)
	{
		opt=read(),x=read(),y=read();
		if(opt==1)c=read(),modify(1,1,n,x,y,c);
		if(opt==2)
		{
			//ans=0;
			// ans=-1<<30;query(1,1,n,x,y);printf("%d\n",ans);
			printf("%d\n",query(1,1,n,x,y));
		}
	}
	return 0;
}
