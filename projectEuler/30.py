n=int(input())
tot=0
for i in range(10,10**(n+1)):
	a=i
	es=0
	while a>0:
		ind=a%10
		es+=(ind**n)
		a//=10
	if es==i:
		print(i)
		tot+=i
print(tot)