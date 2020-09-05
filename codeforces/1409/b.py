for t in range(int(input())):
	a,b,x,y,n = map(int, input().split())
	b1 = max(y,b-n)
	l1 = n-b+b1
	a1 = max(x,a-l1)
	a2 = max(x,a-n)
	l2 = n-a+a2
	b2 = max(y,b-l2)
	print(min(a1*b1,a2*b2))