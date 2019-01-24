m=10000001
cri=[0]*m
pri=list()
for i in range(2,m):
	if cri[i]==0:
		cri[i]=i
		pri.append(i)
		for j in range(i*i,m,i):
			cri[j]=i
print("criba lista")

mina=10000000000000000000000000000
def dfs(a,b,n,l):
	global mina
	if l < 0:
		return
	if b*94744<15499*(a-1) and a<mina:
		print(a,b,b/(a-1),l)
		mina=a
	if n >=0:
		dfs(a*pri[n],b*pri[n],n,l-1)
	dfs(a*pri[n+1],b*(pri[n+1]-1),n+1,l-1)
dfs(1,1,-1,22)