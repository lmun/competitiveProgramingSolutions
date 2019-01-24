from math import sqrt
def poliTest(p,n):
	a=(n-4)*(n-4)+8*p*(n-2)
	b=int(sqrt(a))
	if a!=b*b:
		return False
	if n==2:
		return True
	c=b+n-4
	d=2*(n-2)
	return c%d==0

#for i in range(2,30):
	#print(i,poliTest(i,3),poliTest(i,4),poliTest(i,5),poliTest(i,6),poliTest(i,7),poliTest(i,8))
	"""
tot=0
toti=set()
for i in range(10,100):
	#print(i)
	for j in range(10,100):
		#print(i,j)
		for k in range(10,100):
			#print(i,j,k)
			ord=[i,j,k]
			nums=list()
			for kk in range(len(ord)-1):
				nums.append(int(str(ord[kk])+str(ord[(kk+1)%len(ord)])))
			if all(any(poliTest(pp,pn) for pn in range(3,9)) for pp in nums):
				#for n in nums:
					#print(n)
				#print(i,j,k)
				toti.add(i)
				if k in toti:
					print(k)
"""

def busca(n,d,s,ori):
	if d==0:
		#print(n,ori,n)
		return n==ori
	#print(n)
	for i in range(10,100):
		for j in range(3,9):
			if j not in s and j in nums and poliTest(100*n+i,j):
				mis=set(s)
				mis.add(j)
				#print(100*n+i,j)
				we=busca(i,d-1,mis,ori)
				if we > 0:
					print(j,100*n+i)
					return we+100*n+i
	return 0

"""
for i in range(19,59):
	octa=i*(3*i-2)
	s=set()
	s.add(8)
	if octa%100 >9 and busca(octa%100,5,s,octa//100):
		print(i,octa,'\n')
"""
def poli(s,n):
	return (n*n*(s-2)-n*(s-4))//2

n=int(input())
nums=list(map(int,input().split()))
i=0
res=list()
while True:
	i+=1
	pol=poli(nums[-1],i)
	if pol < 1000:
		continue
	if pol > 9999:
		break
	s=set()
	s.add(nums[-1])
	if pol%100 > 9:
		we=busca(pol%100,n-1,s,pol//100)
		if we > 0:
			res.append(we+pol-1)
res.sort()
for r in res:
	print(r)