from math import sqrt

def isPenta(num):
	nu=24*num+1
	rai=int(sqrt(nu))
	return rai*rai==nu and rai%6==5

def isHexa(num):
	nu=8*num+1
	rai=int(sqrt(nu))
	return rai*rai==nu and rai%4==3

no,a, b = input().strip().split(' ')
no,a, b = [int(no), int(a), int(b)]
i=0
r=0
while True:
	i+=1
	if a==3:
		n=(i*(i+1))//2
	else:
		n=(i*(3*i-1))//2
	if n>no:
		break
	if b==5 and isPenta(n):
		print(n)
	if b==6 and isHexa(n):
		print(n)