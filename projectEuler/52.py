def samedigi(a,b):
	sa=str(a)
	sb=str(b)
	if len(sa)!= len(sb):
		return False
	conb=[0]*10
	for d in str(a):
		conb[int(d)]+=1
	for d in str(b):
		conb[int(d)]-=1
	for i in range(10):
		if conb[i]!=0:
			return False
	return True
n,k=map(int,input().split())
for i in range(125874,n):
	if all(samedigi(i,i*j) for j in range(2,k+1)):
		for t in range(k):
			print((i*(t+1)), end=" ")
		print()
