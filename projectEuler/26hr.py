m=3
mv=0
lim=1005
res=[0]*lim
pri=res=[0]*lim
for x in range(2,lim):
	if pri[x]!=0:
		res[x]=m
		continue
	for o in range(x*x,lim,x):
		pri[o]=x
	se=list()
	a=1
	while True:
		while a < x:
			a*=10
		a%=x
		#print(a)
		if a==0:
			break
		if a in se:
			if len(se)-se.index(a)>mv:
				mv=len(se)-se.index(a)
				m=x
			break
		else:
			se.append(a)
	res[x]=m
	print(str(x)+" - "+str(m))
for _ in range(int(input())):
	s = int(input())
	print(res[s])
