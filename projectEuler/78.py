import matplotlib.pyplot as plt

m=10001
dp=[[-1]*m for _ in range(m)]
def ways(n,t):
	if dp[n][t]>=0:
		return dp[n][t]
	if n < 2:
		return 0
	if t > n:
		return 0
	tot=1
	for i in range(t,n):
		if n>=2*i:
			tot+=ways(n-i,i)
	dp[n][t]=tot
	return dp[n][t]
ant=9
xa=list()
ya=list()
for i in range(2,100):
	x=1+ways(i,1)
	print(i,x,x-ant)
	xa.append(i)
	ya.append(x)
	ant=x

plt.plot(xa, ya, 'ro')
#plt.axis([0, 6, 0, 20])
plt.show()
