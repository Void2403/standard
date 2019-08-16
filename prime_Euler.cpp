void init()
{
	s[1]=1;
	for(int i=2;i<=maxn;i++)
	{
		if(s[i]==0) 
			s[i]=p[++p[0]]=i;
		for(int j=1;j<=p[0];j++)
		{
			int k = i* p[j]; 
			if(k>maxn || p[j]>s[i]) break; 
			s[k]=p[j];
		}
	}
	return;
}