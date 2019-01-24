#!/usr/bin/python3
import itertools
no,k=map(int,input().split())
m=1000000
cri=[0]*m
pri=list()
for i in range(2,m):
	if cri[i]==0:
		pri.append(i)
		for j in range(i*i,m,i):
			cri[j]+=1

def esprimo(n):
	if n < m:
		return cri[n]==0
	for p in pri:
		if p*p > n:
			return True
		elif n%p==0:
			return False
	return True

def esparprimo(a,b):
	return esprimo(int(str(a)+str(b))) and esprimo(int(str(b)+str(a)))
	#print("espar",a,b,int(str(a)+str(b)))
		
def estriprimo(a,b,c):
	return esparprimo(a,b) and esparprimo(a,c) and esparprimo(b,c)
	
res=set()
for i in range(len(pri)):
	if pri[i] >= no:
		break
	pares=list()
	pares.append(pri[i])
	for j in range(i):
		if all(esparprimo(ppp,pri[j]) for ppp in pares):
			#print(pri[i],pri[j])
			pares.append(pri[j])
	if len(pares)==k:
		su=0
		#print(len(pares))
		for pp in pares:
			#print(pp)
			su+=pp
		#print(su)
		res.add(su)
		#break
	if len(pares)>k:
		for c in itertools.combinations(pares,k):
			su=0
			for tt in c:
				su+=tt
			res.add(su)
re=list(sorted(res))
for r in re:
	print(r)