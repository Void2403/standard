#include<cstdio>

using namespace std;

int n,m,ans,x,tmp[110],mn,len;

int min(int x,int y){return x<y?x:y;}

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

struct STACK_MAX
{
	int len=0;
	int a[1100];
	void up(int x)
	{
		while (x>1 && a[x]>a[x>>1])
		{
			swap(a[x],a[x>>1]);
			x>>=1;
		}
	}
	void down(int x)
	{
		int y;
		while ((2*x<=len && a[x]<a[x<<1]) || (2*x+1<=len && a[x]<a[x*2+1]))
		{
			y=2*x;
			if (2*x+1<=len && a[2*x+1]>a[2*x]) y=2*x+1;
			swap(a[x],a[y]);
			x=y;
		}
	}
	void push(int x)
	{
		a[++len]=x;
		up(len);
	}
	int top(){return a[1];}
	void pop(){
		a[1]=a[len--];
		down(1);
		return;
	}
}stk;

int main()
{
	
}