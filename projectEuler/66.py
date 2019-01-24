from math import sqrt

def egcd(a, b):
	if a == 0:
		return (b, 0, 1)
	else:
		g, x, y = egcd(b % a, a)
		return (g, y - (b // a) * x, x)



res=0
for i in range(2,1000):
	x=int(sqrt(i))
	#print(i,x)
	if x*x==i:
		continue
	a,b,c=egcd(1,i)
	print(a,b,c)
	res=max(a,res)
	#print(i,r,res,sqrt(res))