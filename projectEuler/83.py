limi=80
ori=list()
dp=[[0]*limi for _ in range(limi)]
for i in range(limi):
	ori.append([int(x) for x in input().split(',')])
dirs=[(-1,0),(1,0),(0,1),(0,-1)]

def visi(t,a,b):
	#print(t,a,b)
	if a<0 or b<0 or a>=limi or b>=limi:
		return
	nu=t+ori[a][b]
	if dp[a][b]==0 or nu<dp[a][b]:
		if nu<dp[a][b]:
			print(t,a,b,dp[a][b]-nu)
		dp[a][b]=nu
		for x,y in dirs:
			visi(nu,a+x,b+y)
#visi(0,0,0)
#print(dp[limi-1][limi-1])

cola=list()
cola.append((0,0,0))
while cola:
	t,a,b=cola.pop()
	#print(t,a,b)
	if a<0 or b<0 or a>=limi or b>=limi:
		continue
	nu=t+ori[a][b]
	for x,y in dirs:
		if a+x>=0 and b+y>=0 and a+x<limi and b+y<limi:
			if dp[a+x][b+y]==0:
				dp[a+x][b+y]=nu+ori[a+x][b+y]
				cola.insert(0,(nu,a+x,b+y))
			elif dp[a+x][b+y]>nu+ori[a+x][b+y]:
				dp[a+x][b+y]=nu+ori[a+x][b+y]
				cola.insert(0,(nu,a+x,b+y))
print(dp[limi-1][limi-1])
#for i in range(limi):
#	print(', '.join(map(str, dp[i])))