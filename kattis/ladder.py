from math import *
x,y=map(int,input().split())
if y!=30:
	print(ceil(x/sin(radians(y))))
else:
	print(2*x)
