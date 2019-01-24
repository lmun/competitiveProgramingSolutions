from math import sqrt

def isPenta(num):
	nu=24*num+1
	rai=int(sqrt(nu))
	return rai*rai==nu and rai%6==5

n, gg = input().strip().split(' ')
n, gg = [int(n), int(gg)]

resu=list()
penta=list()
pent=set()
for i in range(1,n+1):
	penta.append((i*(3*i-1))//2)
	#pent.add((i*(3*i-1))//2)
for k in range(1,gg):
	for a in range(len(penta)-k):
		if isPenta(penta[a+k]-penta[a]) and isPenta(penta[a+k]+penta[a]):
			resu.append(penta[a+k]-penta[a])
resu.sort()
for g in resu:
	print(g)