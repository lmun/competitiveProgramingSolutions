from itertools import accumulate

def getprimes(m):
	cri = [0]*m
	pri = []
	for i in range(2,m):
		if cri[i] == 0:
			cri[i]=i
			for j in range(i*i, m, i):
				cri[j] = i
			pri.append(i)
	return pri

# m = 5*10**7+5
m=10**6
# m = 105
tot = [0]*m
pri = getprimes(m)

tot[0]=tot[1]=0
# print('criba')
print(len(pri))
def auxi(a, b, c, d):
	if a >=m:
		return
	tot[a] = (a//d)*c
	auxi(a*pri[b],b,c,d)
	for n in range(b+1,len(pri)):
		if a*pri[n] >= m:
			break
		auxi(a*pri[n],n,c*(pri[n]-1),d*pri[n])
for i,p in enumerate(pri):
	auxi(p,i,p-1,p)
	# print(p)
# print(len(tot))
# re = tot

# for i in range(100):
# 	if i%12==0:
# 		print()
# 	print('{:<4}'.format(re[i]), end='')
# print()

# f = [0]*m
# for i in range(m):
# 	f[i] = (pow(i,i,i+1)+i)%(i+1)
# print(f)
# tots = [toti(i) for i in range(20)]
# print(tots)