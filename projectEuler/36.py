def invBase(n,b=10):
	res=0
	while n>0:
		res*=b
		res+=n%b
		n//=b
	return res

n, k = input().strip().split(' ')
n, k = [int(n), int(k)]
#print(invBase(n,k))
res=0
for i in range(n):
	if invBase(i,k)==i and invBase(i,10)==i:
		res+=i
print(res)