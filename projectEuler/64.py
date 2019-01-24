from math import sqrt
def period(n):
	a=int(sqrt(n))
	b=n-a*a
	c=0
	if b==0:
		return 0
	t=(1,a)
	s=set()
	while t not in s:
		s.add(t)
		x,y=t
		#print(x,y)
		p=(n-y*y)//x
		y=-1*y
		while (y+p)*(y+p)<=n:
			y+=p
		#print(p,y)
		t=(p,y)
		c+=1
	return c

res=0
for i in range(int(input())+1):
	#print(i,period(i))
	if period(i)%2==1:
		res+=1
print(res)