#!/usr/bin/env python3.5
def sumdigits(n):
	r=0
	while n>0:
		r+=n%10
		n//=10
	return r

nu=int(intput())
m=0
for i in range(nu):
	for j in range(nu):
		b=sumdigits(i**j)
		m=max(b,m)
print(m)