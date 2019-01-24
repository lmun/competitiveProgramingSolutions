def digit(n):
	if n < 10:
		return n
	n-=1
	l=1
	h=1
	t=h*9*l
	while n-t >= 0:
		#print(n,t,l,h)
		n-=t
		l+=1
		h*=10
		t=h*9*l
	#print(n,t,l)
	return str(n//(l)+h)[n%l]
for a in range(int(input())):
	nums=list(map(lambda x:int(x),input().split()))
	r=1
	for n in nums:
		r*=int(digit(n))
	print(r)
