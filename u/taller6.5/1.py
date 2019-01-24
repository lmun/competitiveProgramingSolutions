#!/usr/bin/python3.5
while True:
	n,m = map(int,input().split())
	if n==0:
		break
	x=list()
	for _ in range(m):
		x.append(set(list(map(int,input().split()))[1:]))
	s=set()
	s.add(0)
	c=True
	while c:
		c=False
		for i in range(m):
			if len(s&x[i])>0 and not s >= x[i]:
				c=True
				s|=x[i]
	print(len(s))