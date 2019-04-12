
#include<cstdio>
using namespace std;
int a[600000],n,b[600000];
long long ans=0;
void mergesort(int l,int r){
    if (l==r)return;
    int mid=(l+r)/2;
    mergesort(l,mid);
    mergesort(mid+1,r);
    long  i=l,j=mid+1,k=l;
    while (i<=mid && j<=r){
        if (a[i]<=a[j]){b[k]=a[i];i++;k++;}
        else{b[k]=a[j];j++;k++;ans+=(mid-i+1);}
    }
    while (i<=mid){
        b[k]=a[i];i++;k++;
    }
    while(j<=r){
        b[k]=a[j];j++;k++;
    }
    for (i=l;i<=r;i++) a[i]=b[i];
}
int main(){
    scanf("%d",&n);
    for (int i=1;i<=n;i++) scanf("%d",&a[i]);
    mergesort(1,n); 
    for (int i=1;i<=n;i++) printf("%d ",a[i]);//从大到小
    printf("%lld",ans);//逆序对个数
}
