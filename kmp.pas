//给出两个字符串 s1 和 s2 ，字符串满足长度小于100,000。现要求出s1中出现s2子串的所有位置。（位置编号从1到N）
var 
	n,lena,i,j:Longint;
	nex:array[1..110000] of Longint;
	a,b:ansistring;
begin
	readln(lena,n);
	readln(a);
	readln(b);
	for i := 2 to n do 
	begin
		while (j>0)and(b[j+1]<>b[i]) do j:=nex[j];
		if b[j+1]=b[i] then inc(j);
		nex[i]:=j;
	end;
	j:=0;
	for i:=1 to lena do 
	begin
		while (j>0)and(b[j+1]<>a[i]) do  j:=nex[j];
		if b[j+1]=a[i] then inc(j);
		if j=n then
		begin
			writeln(i-n+1);
			j:=nex[j];
		end;
	end;
end.