#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

int n,a[310000],x,y,ans=0,cnt=0;

struct cmp
{
    bool operator()(int a,int b)
    { 
        return a>b;
    } 
};

priority_queue<int,vector<int>,cmp> q;

inline int read()
{
	int x=0;char c=getchar();
	while(c<'0' || c>'9')c=getchar();
	while(c>='0' && c<='9')x=(x<<1)+(x<<3)+(c^48),c=getchar();
	return x;
}

int main()
{
	freopen("jzoj1774.in","r",stdin);
	cnt=n=read();
	for(int i=1;i<=n;i++)a[i]=read(),q.push(a[i]);
	while(!q.empty())
	{
		x=q.top();q.pop();cnt--;
		if(cnt==0)break;
		y=q.top();q.pop();cnt--;
		if(y==0)break;
		ans+=x+y;
		q.push(x+y);cnt++;
	}
	printf("%d\n",ans);
	return 0;
}