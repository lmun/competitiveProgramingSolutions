n=int(input())
res=0
nu=[1]*(n+1)
for i in range(2,n+1):
	a=i*i
	c=2
	while a <= n:
		nu[a]=c
		c+=1
		a*=i
	print(i," - ",nu[i]," = ",res)
	res+=n-1
	if nu[i]>1:
		res-=(n//nu[i])
print(res)
