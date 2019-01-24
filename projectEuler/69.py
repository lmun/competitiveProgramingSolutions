m=1000001
cri=[0]*m
for i in range(2,m):
	if cri[i]==0:
		cri[i]=i
		for j in range(i*i,m,i):
			cri[j]=i


def toti(n):
	t=1
	while n > 1:
		d=cri[n]
		c=0
		while n%d==0:
			n//=d
			c+=1
		t*=(d-1)*(d**(c-1))
	return t

me=1
ne=1
for i in range(m):
	#print(i,toti(i))
	e=i/toti(i)
	if e > me:
		me=e
		ne=i
		print(me,ne)
print(me,ne)