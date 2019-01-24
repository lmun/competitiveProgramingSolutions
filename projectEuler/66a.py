from math import sqrt
sq=set()
l=10000000
ma=0
for i in range(2,1001):
	a=int(sqrt(i))
	if a*a==i:
		continue
	j=1
	t=j*j*i+1 
	it=int(sqrt(t))
	for _ in range(1,10**7):
		if it*it==t:
			ma=max(ma,it)
			break
		j+=1
		t=j*j*i+1 
		it=int(sqrt(t))
	else:
		continue
	print(i,it)
print(ma)